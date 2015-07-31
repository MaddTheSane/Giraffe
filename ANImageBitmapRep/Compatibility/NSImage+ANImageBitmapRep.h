//
//  NSImage+ANImageBitmapRep.h
//  ImageBitmapRep
//
//  Created by Alex Nichol on 10/23/11.
//  Copyright (c) 2011 __MyCompanyName__. All rights reserved.
//

#if TARGET_OS_IPHONE != 1

#import <Cocoa/Cocoa.h>

@class ANImageBitmapRep;

NS_ASSUME_NONNULL_BEGIN

@interface NSImage (ANImageBitmapRep)

+ (nullable NSImage *)imageFromImageBitmapRep:(ANImageBitmapRep *)ibr;
- (ANImageBitmapRep *)imageBitmapRep;
- (NSImage *)imageByScalingToSize:(CGSize)sz;
- (NSImage *)imageFittingFrame:(CGSize)sz;
- (NSImage *)imageFillingFrame:(CGSize)sz;

@end

NS_ASSUME_NONNULL_END

#endif
