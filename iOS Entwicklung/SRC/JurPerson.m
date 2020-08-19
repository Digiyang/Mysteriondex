//
//  JurPerson.m
//  InDemo
//
//  Created by Dragan Macos on 12.12.13.
//  Copyright (c) 2013 Dragan Macos. All rights reserved.
//

#import "JurPerson.h"

@implementation JurPerson
@synthesize gesellschaftsForm;

-(id) initWithGesellschaftsform:(NSString *)myGesellschaftsform
{
    
    if (self = [super init])
    {
        self.gesellschaftsForm = myGesellschaftsform;
    }
    return self;
}

-(void) logMe
{
    NSLog(@"<<JurPerson; ID=%d, gesellscfaftsform=%@, name=%@",
          self.ID, self.gesellschaftsForm, self.name);
}
@end
