//
//  ANMutableColorArray.h
//  GifPro
//
//  Created by Alex Nichol on 11/2/11.
//  Copyright (c) 2011 __MyCompanyName__. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "ANColorTable.h"

NS_ASSUME_NONNULL_BEGIN

@interface ANMutableColorArray : NSObject

- (instancetype)init;

@property (readonly, NS_NONATOMIC_IOSONLY) NSUInteger count;
- (void)addColor:(ANGifColor)color;
- (void)removeAtIndex:(NSUInteger)index;
- (ANGifColor)colorAtIndex:(NSUInteger)index;

- (void)sortByBrightness;
- (ANMutableColorArray *)colorArrayByAveragingSplit:(NSUInteger)numColors;
- (void)removeDuplicates;
- (ANGifColor)averagePopFirst;

@end

NS_ASSUME_NONNULL_END
