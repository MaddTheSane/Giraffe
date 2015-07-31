//
//  UIImage+ANImageBitmapRep.h
//  ImageBitmapRep
//
//  Created by Alex Nichol on 8/11/11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#if TARGET_OS_IPHONE

@class ANImageBitmapRep;

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface UIImage (ANImageBitmapRep)

+ (nullable UIImage *)imageFromImageBitmapRep:(ANImageBitmapRep *)ibr;
- (ANImageBitmapRep *)imageBitmapRep;
- (UIImage *)imageByScalingToSize:(CGSize)sz;
- (UIImage *)imageFittingFrame:(CGSize)sz;
- (UIImage *)imageFillingFrame:(CGSize)sz;

@end

NS_ASSUME_NONNULL_END

#endif
