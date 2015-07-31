//
//  ANGifNetscapeAppExtension.h
//  GifPro
//
//  Created by Alex Nichol on 11/3/11.
//  Copyright (c) 2011 __MyCompanyName__. All rights reserved.
//

#import "ANGifAppExtension.h"

NS_ASSUME_NONNULL_BEGIN

@interface ANGifNetscapeAppExtension : ANGifAppExtension {
	UInt16 numberOfRepeats;
}

@property (readonly) UInt16 numberOfRepeats;

- (instancetype)init;
- (instancetype)initWithRepeatCount:(UInt16)repeats NS_DESIGNATED_INITIALIZER;

@end

NS_ASSUME_NONNULL_END
