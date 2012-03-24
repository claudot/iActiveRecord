//
//  Project.m
//  iActiveRecord
//
//  Created by Alex Denisov on 22.03.12.
//  Copyright (c) 2012 CoreInvader. All rights reserved.
//

#import "Project.h"

@implementation Project

@synthesize name;

has_many_through_imp(User, UserProjectRelationship, users)

validation_do(
    validate_presence_of(name)
    validate_uniqueness_of(name)
)

@end
