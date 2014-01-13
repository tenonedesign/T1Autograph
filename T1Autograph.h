/*	Usage Instructions:
 
 Drag the T1Autograph folder into your XCode project.  Make sure you link to CoreGraphics.framework.
 
 1) #import "T1Autograph.h" in your view controller, then add <T1AutographDelegate> to your .h file after the superclass name.
 
 2) Use one of the two class methods to obtain a signature.
 - The easiest way (with a modal window) is by calling [T1Autograph autographWithDelegate:self modalDisplayString:nil];
 - To obtain a signature from your choice of UIView, call [T1Autograph autographWithView:myUIView delegate:self];
 
 3) Implement autograph:didCompleteWithSignature: in your view controller.  The T1Signature object you'll receive is defined in T1Signature.h.
 
 4) Once it's working for you, you can remove the watermark.  Use [autographInstance setLicenseCode:@"your40digitlicensecode"]; Purchase @"your40digitlicensecode" at http://tenonedesign.com/t1autograph
 
 For more usage info and examples, delve into the T1Autograph demo project.
 Support requests may be emailed to devs@tenonedesign.com
 Follow @tenonedesign for library update notifications
 
 */

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "T1Signature.h"
@class T1Autograph;


#pragma mark - Delegate Protocol

@protocol T1AutographDelegate <NSObject>
@optional
- (void)autographDidCancelModalView:(T1Autograph *)autograph;			// user canceled autograph modal view
- (void)autographDidCompleteWithNoSignature:(T1Autograph *)autograph;	// user pressed the done button without signing
- (void)autograph:(T1Autograph *)autograph didCompleteWithSignature:(T1Signature *)signature;   // signature was successful
- (void)autograph:(T1Autograph *)autograph didEndLineWithSignaturePointCount:(NSUInteger)count; // Called when a signature stroke has ended. Can be used to toggle state of clear/undo/done UI in your own custom view.
@end



@interface T1Autograph : NSObject

#pragma mark - Properties

@property (strong, nonatomic) NSString *licenseCode;	// required to remove watermark.  See instructions above.
@property (assign, nonatomic) BOOL showGuideline;		// defaults to YES
@property (strong, nonatomic) UIColor *strokeColor;		// defaults to black
@property (assign, nonatomic) float strokeWidth;		// starting line width. defaults to 6.0f
@property (assign, nonatomic) float velocityReduction;	// amount the line narrows with pen speed.  defaults to 0.85f
@property (assign, nonatomic) BOOL swipeToUndoEnabled;	// defaults to YES
@property (assign, nonatomic) BOOL showDate;			// defaults to NO
@property (assign, nonatomic) BOOL showHash;			// defaults to NO
@property (strong, nonatomic) NSString *customHash;		// custom hash or string you'd like.  If nil, will use a random hash.
@property (assign, nonatomic) float exportScale;		// defaults to 1.0f
@property (assign, nonatomic) BOOL clipSignatureToBounds;	// force signature to same dimensions as the enclosing view
@property (assign, readonly) NSUInteger buildNumber;	// good to know if you have a support request



#pragma mark - Methods

/**
 @brief Pops a built-in modal view to accept a signature
 @param delegate Object designated to receive messages declared in the T1AutographDelegate protocol
 @param displayString String to display in the modal view when accepting a signature
 @return A reference to a newly created T1Autograph object.
 @discussion This is a simple method to obtain a signature with a minimum of fuss.  Be sure to set the license code of this object directly after calling this method to avoid a watermark.
 */
+ (id)autographWithDelegate:(UIViewController<T1AutographDelegate> *)delegate modalDisplayString:(NSString *)displayString;

/**
 @brief Captures a signature in the supplied view
 @param theView A NSView or subclass of NSView.
 @param delegate Object designated to receive messages declared in the T1AutographDelegate protocol
 @return A reference to a newly created T1Autograph object.
 @discussion Use this method when you would like to customize the view used to capture a signature.  Be sure to set the license code of this object directly after calling this method to avoid a watermark.
 */
+ (id)autographWithView:(id)theView delegate:(id<T1AutographDelegate>)delegate;

/**
 @brief Resets the signature view, erasing any existing strokes.
 @param sender The object sending the message.
 @discussion This is generally wired up to a clear button, for those times when your signature resembles the scrawling of a drunken waterfoul.
 */
- (IBAction)reset:(id)sender;

/**
 @brief Completes the signature, forcing a delegate callback message.
 @param sender The object sending the message.
 @discussion This is generally wired up to a done button.  It will cause T1Autograph to send a autographDidCompleteWithSignature: message if the signature was started, or didCompleteWithNoSignature message otherwise.
 */
- (IBAction)done:(id)sender;

@end




