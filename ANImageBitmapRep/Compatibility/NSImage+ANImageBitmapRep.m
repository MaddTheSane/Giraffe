//
//  NSImage+ANImageBitmapRep.m
//  ImageBitmapRep
//
//  Created by Alex Nichol on 10/23/11.
//  Copyright (c) 2011 __MyCompanyName__. All rights reserved.
//

#if TARGET_OS_IPHONE != 1

#import "NSImage+ANImageBitmapRep.h"
#import "ANImageBitmapRep.h"

@implementation NSImage (ANImageBitmapRep)


+ (NSImage *)imageFromImageBitmapRep:(ANImageBitmapRep *)ibr {
	return [ibr image];
}

- (ANImageBitmapRep *)imageBitmapRep {
	return [[ANImageBitmapRep alloc] initWithImage:self];
}

- (NSImage *)imageByScalingToSize:(CGSize)sz {
	ANImageBitmapRep * imageBitmap = [[ANImageBitmapRep alloc] initWithImage:self];
	[imageBitmap setSize:BMPointMake(round(sz.width), round(sz.height))];
	NSImage * scaled = [imageBitmap image];
	return scaled;
}

- (NSImage *)imageFittingFrame:(CGSize)sz {
	ANImageBitmapRep * imageBitmap = [[ANImageBitmapRep alloc] initWithImage:self];
	[imageBitmap setSizeFittingFrame:BMPointMake(round(sz.width), round(sz.height))];
	NSImage * scaled = [imageBitmap image];
	return scaled;
}

- (NSImage *)imageFillingFrame:(CGSize)sz {
	ANImageBitmapRep * imageBitmap = [[ANImageBitmapRep alloc] initWithImage:self];
	[imageBitmap setSizeFillingFrame:BMPointMake(round(sz.width), round(sz.height))];
	NSImage * scaled = [imageBitmap image];
	return scaled;
}

@end

#endif
