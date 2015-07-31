//
//  ANGifImageDescriptor.h
//  GifPro
//
//  Created by Alex Nichol on 11/1/11.
//  Copyright (c) 2011 __MyCompanyName__. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "ANGifImageFrame.h"

#define kImageSeparator 0x2C

@interface ANGifImageDescriptor : NSObject {
	__weak ANGifImageFrame * imageFrame;
}

- (instancetype)initWithImageFrame:(ANGifImageFrame *)anImage NS_DESIGNATED_INITIALIZER;
- (NSData *)encodeBlock;

@end
