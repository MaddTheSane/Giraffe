//
//  UIImage+ANImageBitmapRep.m
//  ImageBitmapRep
//
//  Created by Alex Nichol on 8/11/11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#if TARGET_OS_IPHONE

#import "UIImage+ANImageBitmapRep.h"
#import "ANImageBitmapRep.h"

@implementation UIImage (ANImageBitmapRep)


+ (UIImage *)imageFromImageBitmapRep:(ANImageBitmapRep *)ibr {
	return [ibr image];
}

- (ANImageBitmapRep *)imageBitmapRep {
	return [[ANImageBitmapRep alloc] initWithImage:self];
}

- (UIImage *)imageByScalingToSize:(CGSize)sz {
	ANImageBitmapRep * imageBitmap = [[ANImageBitmapRep alloc] initWithImage:self];
	[imageBitmap setSize:BMPointMake(round(sz.width), round(sz.height))];
	UIImage * scaled = [imageBitmap image];
	return scaled;
}

- (UIImage *)imageFittingFrame:(CGSize)sz {
	ANImageBitmapRep * imageBitmap = [[ANImageBitmapRep alloc] initWithImage:self];
	[imageBitmap setSizeFittingFrame:BMPointMake(round(sz.width), round(sz.height))];
	UIImage * scaled = [imageBitmap image];
	return scaled;
}

- (UIImage *)imageFillingFrame:(CGSize)sz {
	ANImageBitmapRep * imageBitmap = [[ANImageBitmapRep alloc] initWithImage:self];
	[imageBitmap setSizeFillingFrame:BMPointMake(round(sz.width), round(sz.height))];
	UIImage * scaled = [imageBitmap image];
	return scaled;
}

@end

#endif
