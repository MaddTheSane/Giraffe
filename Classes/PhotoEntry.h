//
//  PhotoEntry.h
//  Giraffe
//
//  Created by Alex Nichol on 11/5/11.
//  Copyright (c) 2011 __MyCompanyName__. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIImage.h>
#import "BitmapScaleManipulator.h"

@interface PhotoEntry : NSObject

@property (strong, readonly) UIImage * image;
@property (strong, readonly) NSString * imageName;

- (instancetype)initWithName:(NSString *)name image:(UIImage *)anImage;

@end
