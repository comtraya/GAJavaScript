/*
 Copyright (c) 2010 Andrew Goodale. All rights reserved.
 
 Redistribution and use in source and binary forms, with or without modification, are
 permitted provided that the following conditions are met:
 
 1. Redistributions of source code must retain the above copyright notice, this list of
 conditions and the following disclaimer.
 
 2. Redistributions in binary form must reproduce the above copyright notice, this list
 of conditions and the following disclaimer in the documentation and/or other materials
 provided with the distribution.
 
 THIS SOFTWARE IS PROVIDED BY ANDREW GOODALE "AS IS" AND ANY EXPRESS OR IMPLIED
 WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND
 FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL <COPYRIGHT HOLDER> OR
 CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
 ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
 NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF
 ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 
 The views and conclusions contained in the software and documentation are those of the
 authors and should not be interpreted as representing official policies, either expressed
 or implied, of Andrew Goodale.
*/

#import <UIKit/UIKit.h>

static NSString* const GAJavaScriptErrorDomain;

/*
 * This class provides an Objective-C interface to a JavaScript Object.
 */
@interface GAScriptObject : NSObject 
	<NSFastEnumeration>
{
	/* The object used for relative references (e.g. "document"). */
	NSString*	m_objReference;
	
	/* The javascript "engine" */
	UIWebView*	m_webView;
}

/*
 * Designated initializer.
 */
- (id)initForReference:(NSString *)reference view:(UIWebView *)webView;
	
/*
 * Array containing the names of all the JS properties.
 */
- (NSArray *)allKeys;

/*
 * Call a function with no arguments on this object.
 */
- (id)callFunction:(NSString *)functionName;

/*
 * Call a function on this object, with a single argument.
 */
- (id)callFunction:(NSString *)functionName withObject:(id)argument;

/*
 * Call a function on this object, with a single argument.
 */
- (id)callFunction:(NSString *)functionName withArguments:(NSArray *)arguments;

@end

#pragma mark -

@interface GAScriptObject (NSKeyValueCoding)

/*
 * Read a value (or object) with the given name.
 * If the value cannot be retrieved because of a JS syntax error or exception, an NSError value is returned.
 */
- (id)valueForKey:(NSString *)key;

/*
 * Used for assignment
 */
- (void)setValue:(id)value forKey:(NSString *)key;

/*
 * Read a value from an object using a property path.
 */
- (id)valueForKeyPath:(NSString *)keyPath;

@end

#pragma mark -

@interface GAScriptObject (Blocks)

- (void)setFunctionForKey:(NSString *)key withBlock:(void(^)(NSArray* arguments))block;

@end
