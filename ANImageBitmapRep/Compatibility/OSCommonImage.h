//
//  OSCommonImage.h
//  ImageBitmapRep
//
//  Created by Alex Nichol on 10/23/11.
//  Copyright (c) 2011 __MyCompanyName__. All rights reserved.
//

#ifndef ImageBitmapRep_OSCommonImage_h
#define ImageBitmapRep_OSCommonImage_h

#import "CGImageContainer.h"

#if TARGET_OS_IPHONE
#import <UIKit/UIKit.h>
typedef UIImage ANImageObj;
#elif TARGET_OS_MAC
#import <Cocoa/Cocoa.h>
typedef NSImage ANImageObj;
#endif

NS_ASSUME_NONNULL_BEGIN

CGImageRef CGImageFromANImage (ANImageObj * anImageObj);
ANImageObj * __nullable ANImageFromCGImage (CGImageRef imageRef);

NS_ASSUME_NONNULL_END

#endif
