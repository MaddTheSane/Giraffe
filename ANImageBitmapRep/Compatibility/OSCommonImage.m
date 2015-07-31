//
//  OSCommonImage.c
//  ImageBitmapRep
//
//  Created by Alex Nichol on 10/23/11.
//  Copyright (c) 2011 __MyCompanyName__. All rights reserved.
//

#include "OSCommonImage.h"

CGImageRef CGImageFromANImage (ANImageObj * anImageObj) {
#if TARGET_OS_IPHONE
	return [anImageObj CGImage];
#elif TARGET_OS_MAC
	CGImageSourceRef source;
	source = CGImageSourceCreateWithData((__bridge CFDataRef)[anImageObj TIFFRepresentation], NULL);
	CGImageRef maskRef = CGImageSourceCreateImageAtIndex(source, 0, NULL);
	return (CGImageRef)CFAutorelease(maskRef);
#endif
}

ANImageObj * ANImageFromCGImage (CGImageRef imageRef) {
#if TARGET_OS_IPHONE
	return [UIImage imageWithCGImage:imageRef];
#elif TARGET_OS_MAC
	NSImage * image = [[NSImage alloc] initWithCGImage:imageRef size:NSZeroSize];
	return image;
#endif
}
