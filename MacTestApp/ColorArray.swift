//
//  ColorArray.swift
//  Giraffe
//
//  Created by C.W. Betts on 7/31/15.
//
//

import Giraffe

struct ColorArray {
	private var colors = [ANGifColor]()
	
	var count: Int {
		return colors.count
	}
	
	var capacity: Int {
		return colors.capacity
	}
	
	subscript(index: Int) -> ANGifColor {
		return colors[index]
	}
	
	mutating func addColor(color: ANGifColor) {
		for aColor in colors {
			if ANGifColorVariance(color, aColor) < 5 {
				return
			}
		}
		colors.append(color)
	}
	
	mutating func removeAtIndex(index: Int) -> ANGifColor {
		return colors.removeAtIndex(index)
	}
	
	//MARK: Averaging
	
	mutating func sortByBrightness() {
		colors.sort { (lhs, rhs) -> Bool in
			return (Int(lhs.red) + Int(lhs.green) + Int(lhs.blue)) >
				(Int(rhs.red) + Int(rhs.green) + Int(rhs.blue))
		}
	}
	
	func colorArrayByAveragingSplit(numColors: Int) -> ColorArray {
		var newArray = ColorArray()
		
		// calculate number of colors per sector
		let colorsPerSect = colors.count / numColors;
		var colorsRemaining = colors.count % numColors;
		var startIndex = 0;
		
		for i in 0..<numColors {
			var size = colorsPerSect;
			if (colorsRemaining > 0) {
				size += 1;
				colorsRemaining--;
			}
			
			if (size == 0) {
				break
			}
			
			var red = 0.0
			var green = 0.0
			var blue = 0.0
			
			// average <size> colors
			for j in startIndex..<(startIndex + size) {
				let aColor = colors[j];
				red += Double(aColor.red)
				green += Double(aColor.green)
				blue += Double(aColor.blue)
			}
			
			red /= Double(size)
			green /= Double(size);
			blue /= Double(size);
			
			let genColor = ANGifColorMake(UInt8(red), UInt8(green), UInt8(blue));
			newArray.addColor(genColor)
			
			startIndex += size;
		}
		return newArray;
	}
	
	mutating func averagePopFirst() -> ANGifColor {
		if colors.count == 1 {
			return removeAtIndex(0)
		}
		var bestFit = 1;
		var variance: UInt = 255*3;
		var firstColor = colors.first!;
		
		for (i, color) in enumerate(colors) {
			let lVariance = ANGifColorVariance(firstColor, color)
			
			if lVariance < variance {
				bestFit = i
				variance = lVariance
				if variance == 0 {
					break
				}
			}
		}
		
		let selectedColor = removeAtIndex(bestFit)
		removeAtIndex(0)
		return ANGifColorAverage(selectedColor, firstColor);
	}
	
	mutating func removeDuplicates() {
		func uniq<S : SequenceType, T : Hashable where S.Generator.Element == T>(source: S) -> [T] {
			var addedDict = [T:Bool]();
			return filter(source) { addedDict.updateValue(true, forKey: $0) == nil }
		}
		colors = uniq(colors)
	}
}
