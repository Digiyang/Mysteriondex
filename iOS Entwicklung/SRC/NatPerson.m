//
//  NatPerson.m
//  InDemo
//
//  Created by Dragan Macos on 12.12.13.
//  Copyright (c) 2013 Dragan Macos. All rights reserved.
//

#import "NatPerson.h"

@implementation NatPerson

@synthesize wohnort;

-(id) initWithWohnort:(NSString *) myWohnort
{

    if (self = [super init])
    {
        self.wohnort = myWohnort;
    }
    return self;
}

-(id) init
{
    self = [self initWithWohnort:@"Obdachlos"];
    return self;
}

-(void) logMe
{
    NSLog(@"<<NatPerson; ID=%d, wohnort=%@, name=%@",
          self.ID, self.wohnort, self.name);
}

@end
