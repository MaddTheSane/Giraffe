//
//  LZWSpoof.h
//  GifPro
//
//  Created by Alex Nichol on 11/2/11.
//  Copyright (c) 2011 __MyCompanyName__. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

#define BitOutOfRangeException @"BitOutOfRangeException"

@interface LZWSpoof : NSObject {
	UInt8 * _bytePool;
	NSUInteger _totalSize;
	NSUInteger numBits;
}

@property (readonly) NSUInteger numBits;

+ (NSData *)lzwExpandData:(NSData *)existingData;

- (instancetype)initWithData:(NSData *)initialData NS_DESIGNATED_INITIALIZER;
- (instancetype)init NS_DESIGNATED_INITIALIZER;
- (void)addBit:(BOOL)flag;
- (BOOL)getBitAtIndex:(NSUInteger)bitIndex;

- (void)addLZWClearCode;
- (void)addByte:(NSUInteger)startBit fromBuffer:(LZWSpoof *)source;

- (NSData *)convertToData;

@end

NS_ASSUME_NONNULL_END
