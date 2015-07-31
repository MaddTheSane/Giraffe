//
//  ANGifAppExtension.h
//  GifPro
//
//  Created by Alex Nichol on 11/3/11.
//  Copyright (c) 2011 __MyCompanyName__. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface ANGifAppExtension : NSObject

@property (nonatomic, copy) NSData * applicationIdentifier;
@property (nonatomic, copy) NSData * applicationAuthCode;
@property (nonatomic, copy) NSData * applicationData;

- (NSData *)encodeBlock;

@end

NS_ASSUME_NONNULL_END
