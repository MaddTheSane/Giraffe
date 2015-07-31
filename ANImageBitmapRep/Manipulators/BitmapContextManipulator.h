//
//  BitmapContextManip.h
//  ImageBitmapRep
//
//  Created by Alex Nichol on 10/14/11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "BitmapContextRep.h"

@interface BitmapContextManipulator : NSObject <BitmapContextRep> {
	__unsafe_unretained BitmapContextRep * bitmapContext;
}

@property (nonatomic, unsafe_unretained) BitmapContextRep * bitmapContext;

- (instancetype)initWithContext:(BitmapContextRep *)aContext;

@end
