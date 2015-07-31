//
//  ANGifDataSubblock.h
//  GifPro
//
//  Created by Alex Nichol on 11/2/11.
//  Copyright (c) 2011 __MyCompanyName__. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface ANGifDataSubblock : NSObject {
	NSData * subblockData;
}

#ifdef __MAC_10_11
+ (NSArray<ANGifDataSubblock*> *)dataSubblocksForData:(NSData *)largeData;
#else
+ (NSArray *)dataSubblocksForData:(NSData *)largeData;
#endif

- (instancetype)initWithBlockData:(NSData *)theData NS_DESIGNATED_INITIALIZER;
- (NSData *)encodeBlock;
- (void)writeToFileHandle:(NSFileHandle *)fileHandle;

@end

NS_ASSUME_NONNULL_END
