//
//  Giraffe extensions.swift
//  Giraffe
//
//  Created by C.W. Betts on 7/31/15.
//
//

import Giraffe

public func ==(lhs: ANGifColor, rhs: ANGifColor) -> Bool {
	return ANGifColorIsEqual(lhs, rhs)
}

extension ANGifColor: Hashable {
	public var hashValue: Int {
		return Int(red) | Int(green) << 8 | Int(blue) << 16
	}
}
