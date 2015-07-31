//
//  PhotoEntry.m
//  Giraffe
//
//  Created by Alex Nichol on 11/5/11.
//  Copyright (c) 2011 __MyCompanyName__. All rights reserved.
//

#import "PhotoEntry.h"

@implementation PhotoEntry

@synthesize image;
@synthesize imageName;

- (id)initWithName:(NSString *)name image:(UIImage *)anImage {
	if ((self = [super init])) {
		imageName = name;
		if (anImage.size.width > 640 || anImage.size.height > 480) {
			BitmapContextRep * bitmap = [[BitmapContextRep alloc] initWithImage:anImage];
			BitmapScaleManipulator * scale = [[BitmapScaleManipulator alloc] initWithContext:bitmap];
			[scale setSizeFittingFrame:BMPointMake(640, 480)];
			anImage = [[UIImage alloc] initWithCGImage:[scale CGImage]];
		} else {
			image = anImage;
		}
	}
	return self;
}

@end
