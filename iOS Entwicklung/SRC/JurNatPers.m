//
//  JurNatPers.m
//  InDemo
//
//  Created by Dragan Macos on 12.12.13.
//  Copyright (c) 2013 Dragan Macos. All rights reserved.
//


#import "JurNatPers.h"


@implementation JurNatPers
static int currID = 0;
@synthesize ID, name;

+(double) getCurrID {
    return currID;
}

-(id) init {
    if (self = [super init])
    {
        ++currID;
        self.ID = currID;
    }
    return self;
}

-(id) initWithName: (NSString *) myName
{
    self = [self init];
    if (self)
        self.name = myName;
    return self;
}

-(void) logMe
{
    NSLog(@"<<JurNatPerson; ID=%d,  name=%@",
          self.ID, self.name);
}


@end
