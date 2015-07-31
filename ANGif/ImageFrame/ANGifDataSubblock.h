//
//  ANGifDataSubblock.h
//  GifPro
//
//  Created by Alex Nichol on 11/2/11.
//  Copyright (c) 2011 __MyCompanyName__. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface ANGifDataSubblock : NSObject {
	NSData * subblockData;
}

+ (NSArray *)dataSubblocksForData:(NSData *)largeData;

- (instancetype)initWithBlockData:(NSData *)theData NS_DESIGNATED_INITIALIZER;
- (NSData *)encodeBlock;
- (void)writeToFileHandle:(NSFileHandle *)fileHandle;

@end
