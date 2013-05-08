//
//  PlaceKit.h
//  PlaceKitDemo
//
//  Created by Lars Anderson on 5/5/13.
//  Copyright (c) 2013 theonlylars. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef NS_ENUM(NSInteger, PLKTextParagraphLength){
    PLKTextParagraphLengthVeryShort = 0,
    PLKTextParagraphLengthShort,
    PLKTextParagraphLengthMedium,
    PLKTextParagraphLengthLong,
    PLKTextParagraphLengthVeryLong,
};

/** See what these different options do at http://loripsum.net
 */
typedef NS_OPTIONS(NSInteger, PLKTextOptions){
    PLKTextOptionsNone = 0,
    PLKTextOptionsAllCaps = 1 << 0,
    PLKTextOptionsPrude = 1 << 1,
};

extern NSString * const kPLKPlaceKittenImageURLString;
extern NSString * const kPLKPlaceKittenGreyscaleImageURLString;
extern NSString * const kPLKPlaceBaconImageURLString;
extern NSString * const kPLKPlaceHolderImageURLString;
extern NSString * const kPLKPlaceRandomImageURLString;
extern NSString * const kPLKPlaceRandomGreyscaleImageURLString;

@interface PlaceKit : NSObject

//------–----------------
/** Placeholder Images */
//------–----------------

/** Place a kitten image with a given size from placekitten.com
 
 @param size The size in points of your kitten image
 @param completionBlock The block that your kitten image will be returned in
 */
+ (void)placeKittenImageWithSize:(CGSize)size
                      completion:(void(^)(UIImage *kittenImage))completionBlock;

/** Place an image of bacon or other meat with a given size from baconmockup.com
 
 @warning *Warning:* May motivate designers at the expense of developer happiness.
 
 @param size The size in points of your meat-based image
 @param completionBlock The block that your meat-based image will be returned in
 */
+ (void)placeBaconImageWithSize:(CGSize)size
                     completion:(void(^)(UIImage *baconImage))completionBlock;

/** Place a generic placeholder image with a given size from http://placehold.it
 
 @param size The size in points of your placeholder
 @param completionBlock The block that your placeholder image will be returned in
 */
+ (void)placeHolderImageWithSize:(CGSize)size
                      completion:(void(^)(UIImage *placeholderImage))completionBlock;

/** Place a random image in a specific category with a given size from lorempixel.com
 
 @param size The size in points of your random image
 @param category The category that you would like your image to be chosen from. A full list of valid categories can be found at http://lorempixel.com
 @param completionBlock The block that your random image will be returned in
 */
+ (void)placeRandomImageWithSize:(CGSize)size
                        category:(NSString *)category
                      completion:(void(^)(UIImage *randomImage))completionBlock;

/** Place a random greyscale image in a specific category with a given size from lorempixel.com
 
 @param size The size in points of your random greyscale image
 @param category The category that you would like your image to be chosen from. A full list of valid categories can be found at http://lorempixel.com
 @param completionBlock The block that your random image will be returned in
 */
+ (void)placeRandomGreyscaleImageWithSize:(CGSize)size
                                 category:(NSString *)category
                               completion:(void(^)(UIImage *randomImage))completionBlock;

/** Place a random image with a given size from lorempixel.com
 
 @param size The size in points of your random image
 @param completionBlock The block that your placeholder image will be returned in
 */
+ (void)placeRandomImageWithSize:(CGSize)size
                      completion:(void(^)(UIImage *randomImage))completionBlock;

/** Place a random greyscale image with a given size from lorempixel.com
 
 @param size The size in points of your random greyscale image
 @param completionBlock The block that your placeholder image will be returned in
 */
+ (void)placeRandomGreyscaleImageWithSize:(CGSize)size
                               completion:(void(^)(UIImage *randomImage))completionBlock;

//------–------------------
/** @name Placeholder text */
//------–------------------

/** Place some random text with the given parameters from loripsum.net.
 
 @param numberOfParagraphs The number of paragraphs of text that you would like.
 @param paragraphLength The requested length of each paragraph
 @param options A bitmask of PLKTextOptions
 @param completionBlock The block that your random text will be returned in
 */
+ (void)placeTextWithNumberOfParagraphs:(NSInteger)numberOfParagraphs
                               ofLength:(PLKTextParagraphLength)paragraphLength
                                options:(PLKTextOptions)options
                             completion:(void(^)(NSString *placeText))completionBlock;

//------–-------------------
/** @name Placeholder data */
//------–-------------------

/** Place a random first name
 */
+ (NSString *)placeRandomFirstName;

/** Place a random last name
 */
+ (NSString *)placeRandomLastName;

/** Place a random full name
 */
+ (NSString *)placeRandomFullName;

/** Place a random business name with a given word count
 */
+ (NSString *)placeRandomBusinessNameWithNumberOfWords:(NSUInteger)words;

//------–------------------
/** @name Random numbers */
//------–------------------

/** Place a series of random numbers formatter like a US phone number
 */
+ (NSString *)placeRandomPhoneNumber;

/** Place a random integer less than a given number
 
 @param lessThan A maximum bound for the random number generator
 */
+ (NSInteger)placeRandomIntegerLessThan:(NSInteger)lessThan;

/** Place a random float less than a given number
 
 @param lessThan A maximum bound for the random number generator
 */
+ (CGFloat)placeRandomFloatLessThan:(NSInteger)lessThan;

/** Place a random float within a given range
 
 @param range The range in which the random float be returned
 */
+ (CGFloat)placeRandomFloatInRange:(NSRange)range;

/** Place a random float value in the range [0,1]
 */
+ (CGFloat)placeRandomPercentage;

//------–-----------
/** @name Geometry */
//------–-----------

/** Place a random CGSize with random dimensions bounded by a given range
 
 @param dimensionRange A range to bound each dimension to
 */
+ (CGSize)placeRandomSizeWithDimensionInRange:(NSRange)dimensionRange;

/** Place a random CGSize with unique ranges for each dimension
 
 @param xDimensionRange A range for the dimension in the x-direction (width)
 @param yDimensionRange A range for the dimension in the y-direction (height)
 */
+ (CGSize)placeRandomSizeWithXRange:(NSRange)xDimensionRange
                             yRange:(NSRange)yDimensionRange;

/** Place a random CGRect that is fully contained within another rect.
 
 @param rect A rect to bound the randomly generated rect within
 */
+ (CGRect)placeRandomRectWithinRect:(CGRect)rect;

/** Place a random CGPoint that is located within the bounds of a given rect
 
 @param rect A rect to bound the randomly generated point within
 */
+ (CGPoint)placeRandomPointWithinRect:(CGRect)rect;

@end
