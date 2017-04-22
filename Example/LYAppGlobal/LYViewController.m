//
//  LYViewController.m
//  LYAppGlobal
//
//  Created by DeveloperLY on 04/18/2017.
//  Copyright (c) 2017 DeveloperLY. All rights reserved.
//

#import "LYViewController.h"
#import <LYAppGlobal/LYMacros.h>

#import "LYUserTools.h"

@interface LYViewController ()

@end

@implementation LYViewController

- (void)viewDidLoad
{
    [super viewDidLoad];
	
    
    NSLog(@"%lf", WIDTH_SCREEN);
    
    LYUserTools *tools = [LYUserTools shareLYUserTools];
    LYUserTools *tools1 = [[LYUserTools alloc] init];
    
    NSLog(@"%@--%@", tools, tools1);
}

- (void)didReceiveMemoryWarning
{
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

@end
