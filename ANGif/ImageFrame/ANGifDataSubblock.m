//
//  ANGifDataSubblock.m
//  GifPro
//
//  Created by Alex Nichol on 11/2/11.
//  Copyright (c) 2011 __MyCompanyName__. All rights reserved.
//
//  Converted to Non-ARC 11/4/11

#import "ANGifDataSubblock.h"

@implementation ANGifDataSubblock

+ (NSArray *)dataSubblocksForData:(NSData *)largeData {
	NSMutableArray * array = [[NSMutableArray alloc] init];
	
	NSUInteger length = [largeData length];
	const char * bytes = (const char *)[largeData bytes];
	
	for (NSUInteger index = 0; index < length; index += 255) {
		NSUInteger blockLen = 255;
		if (length - index < blockLen) blockLen = length - index;
		
		NSData * theData = [NSData dataWithBytes:&bytes[index] length:blockLen];
		ANGifDataSubblock * subblock = [[ANGifDataSubblock alloc] initWithBlockData:theData];
		[array addObject:subblock];
	}
	
	return [NSArray arrayWithArray:array];
}

- (instancetype)initWithBlockData:(NSData *)theData {
	if ((self = [super init])) {
		subblockData = theData;
	}
	return self;
}

- (NSData *)encodeBlock {
	NSMutableData * data = [NSMutableData data];
	UInt8 length = (UInt8)[subblockData length];
	[data appendBytes:&length length:1];
	[data appendData:subblockData];
	
	return [NSData dataWithData:data];
}

- (void)writeToFileHandle:(NSFileHandle *)fileHandle {
	UInt8 length = (UInt8)[subblockData length];
	[fileHandle writeData:[NSData dataWithBytes:&length length:1]];
	[fileHandle writeData:subblockData];
}

@end
