//
//  CGContextCreator.h
//  ImageBitmapRep
//
//  Created by Alex Nichol on 7/4/11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/**
 * This class has several static methods for creating bitmap contexts.
 * These methods are pretty much only called when creating a new
 * ANImageBitmapRep.
 */
@interface CGContextCreator : NSObject {
    
}

+ (CGContextRef)newARGBBitmapContextWithSize:(CGSize)size CF_RETURNS_RETAINED;
+ (CGContextRef)newARGBBitmapContextWithImage:(CGImageRef)image CF_RETURNS_RETAINED;

@end

NS_ASSUME_NONNULL_END
