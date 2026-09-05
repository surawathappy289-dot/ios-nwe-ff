//
//  UIConstants.h
//  UI Constants and Configuration
//
//  Created for clean UI organization
//

#ifndef UIConstants_h
#define UIConstants_h

#pragma mark - UI Dimensions

// Panel dimensions
static const CGFloat kPanelWidthCompact = 600.0f;
static const CGFloat kPanelHeightCompact = 320.0f;
static const CGFloat kPanelWidthMedium = 640.0f;
static const CGFloat kPanelHeightMedium = 350.0f;
static const CGFloat kPanelWidthLarge = 660.0f;
static const CGFloat kPanelHeightLarge = 370.0f;

// Sidebar
static const CGFloat kSidebarWidth = 70.0f;
static const CGFloat kTabIconSize = 48.0f;
static const CGFloat kTabIconImageSize = 28.0f;
static const CGFloat kTabSpacing = 8.0f;

// Content area
static const CGFloat kPillHeight = 50.0f;
static const CGFloat kPillSpacing = 7.0f;
static const CGFloat kContentPadding = 10.0f;
static const CGFloat kContentTopInset = 5.0f;
static const CGFloat kContentBottomInset = 10.0f;
static const CGFloat kSeparatorPadding = 25.0f;

// Header
static const CGFloat kHeaderHeight = 70.0f;
static const CGFloat kHeaderButtonWidth = 180.0f;

// Sections
static const CGFloat kSectionLabelHeight = 30.0f;
static const CGFloat kSectionSpacing = 20.0f;

#pragma mark - UI Colors

// Theme colors - Dark mode
static const UIColor* kThemeDarkRedBackground = [UIColor colorWithRed:0.05 green:0.01 blue:0.01 alpha:1.0];
static const UIColor* kThemeDarkBlueBackground = [UIColor colorWithRed:0.01 green:0.01 blue:0.05 alpha:1.0];
static const UIColor* kThemeDarkGreenBackground = [UIColor colorWithRed:0.01 green:0.05 blue:0.01 alpha:1.0];
static const UIColor* kThemeDarkPinkBackground = [UIColor colorWithRed:0.05 green:0.01 blue:0.03 alpha:1.0];

// Theme colors - Light mode
static const UIColor* kThemeLightRedBackground = [UIColor colorWithRed:0.99 green:0.95 blue:0.95 alpha:1.0];
static const UIColor* kThemeLightBlueBackground = [UIColor colorWithRed:0.95 green:0.95 blue:0.99 alpha:1.0];
static const UIColor* kThemeLightGreenBackground = [UIColor colorWithRed:0.95 green:0.99 blue:0.95 alpha:1.0];
static const UIColor* kThemeLightPinkBackground = [UIColor colorWithRed:0.99 green:0.95 blue:0.97 alpha:1.0];

// Pill colors - Dark mode
static const UIColor* kThemeDarkRedPill = [UIColor colorWithRed:0.15 green:0.03 blue:0.03 alpha:1.0];
static const UIColor* kThemeDarkBluePill = [UIColor colorWithRed:0.03 green:0.03 blue:0.15 alpha:1.0];
static const UIColor* kThemeDarkGreenPill = [UIColor colorWithRed:0.03 green:0.15 blue:0.03 alpha:1.0];
static const UIColor* kThemeDarkPinkPill = [UIColor colorWithRed:0.15 green:0.03 blue:0.08 alpha:1.0];

// Pill colors - Light mode
static const UIColor* kThemeLightPill = [UIColor colorWithWhite:0.96 alpha:1.0];

// Border colors
static const CGFloat kBorderWidth = 1.0f;
static const UIColor* kBorderDark = [UIColor colorWithWhite:1.0 alpha:0.08];
static const UIColor* kBorderLight = [UIColor colorWithWhite:0.0 alpha:0.05];

// Glow settings
static const CGFloat kGlowRadius = 8.0f;
static const CGFloat kGlowOpacity = 0.6f;

#pragma mark - Segment Control Constants

static const NSUInteger kSegmentTriggerCount = 3;
static const NSUInteger kSegmentBoneCount = 3;
static const NSUInteger kSegmentPriorityCount = 3;
static const NSUInteger kSegmentColorCount = 5;
static const NSUInteger kSegmentMenuColorCount = 4;
static const NSUInteger kSegmentLanguageCount = 2;

#pragma mark - Tag Constants

// Sidebar
static const NSInteger kSidebarSidebarContainerTag = 1000;
static const NSInteger kSidebarScrollViewTag = 1001;
static const NSInteger kSidebarViewTag = 1002;
static const NSInteger kSidebarSeparatorTag = 3000;
static const NSInteger kSidebarTabButtonBaseTag = 88800;

// Header
static const NSInteger kHeaderButtonTag = 2000;
static const NSInteger kHeaderIconTag = 2001;
static const NSInteger kHeaderTitleTag = 2002;
static const NSInteger kThemeToggleTag = 2003;
static const NSInteger kCloseButtonTag = 2004;

// Content areas
static const NSInteger kContentClipViewTag = 4000;
static const NSInteger kContentScrollViewTag = 4001;
static const NSInteger kContentContainerTag = 4002;

// Pills
static const NSInteger kFeaturePillBaseTag = 1000;
static const NSInteger kFeatureCheckboxTag = 2000;
static const NSInteger kFeatureLabelTag = 3000;

// Segments
static const NSInteger kSegmentIndicatorBaseTag = 9000;
static const NSInteger kSegmentButtonBaseTag = 10000;
static const NSInteger kSegmentPillContainerBaseTag = 77000;
static const NSInteger kSegmentTriggerContainerTag = 77001;
static const NSInteger kSegmentTargetContainerTag = 77002;
static const NSInteger kSegmentPriorityContainerTag = 77003;
static const NSInteger kSegmentLanguageContainerTag = 77004;
static const NSInteger kSegmentColorContainerBaseTag = 77010;
static const NSInteger kToggleLeftButtonTag = 11000;
static const NSInteger kToggleRightButtonTag = 11001;
static const NSInteger kSegmentIndicatorTriggerTag = 9001;
static const NSInteger kSegmentIndicatorTargetTag = 9002;
static const NSInteger kSegmentIndicatorPriorityTag = 9003;
static const NSInteger kSegmentIndicatorLanguageTag = 9004;
static const NSInteger kSegmentIndicatorColorBaseTag = 9010;
static const NSInteger kSegmentIndicatorMenuColorTag = 9020;

// Slider
static const NSInteger kSliderValueLabelTag = 600;

// Language segments
static const NSInteger kLanguageSegmentTag = 77004;
static const NSInteger kLanguageIndicatorTag = 9004;
static const NSInteger kLanguageButtonBaseTag = 41000;

// Color picker segments
static const NSInteger kColorSegmentPillBaseTag = 77010;
static const NSInteger kColorIndicatorBaseTag = 9010;
static const NSInteger kColorButtonBaseTag = 40000;

// Menu color segments
static const NSInteger kMenuColorSegmentPillTag = 77020;
static const NSInteger kSegmentMenuColorContainerTag = 77020;
static const NSInteger kMenuColorIndicatorTag = 9020;
static const NSInteger kMenuColorButtonBaseTag = 50000;

#pragma mark - Animation Constants

static const NSTimeInterval kAnimationStandardDuration = 0.3f;
static const NSTimeInterval kAnimationFastDuration = 0.15f;
static const NSTimeInterval kAnimationSlowDuration = 0.5f;

static const CGFloat kAnimationBounceDamping = 0.7f;
static const CGFloat kAnimationBounceVelocity = 1.0f;
static const CGFloat kAnimationEntranceScale = 0.85f;

#pragma mark - System Icons

static const NSArray* kTabIcons = @[
    @"scope",
    @"eye.fill",
    @"gamecontroller.fill",
    @"wrench.and.screwdriver.fill",
    @"person.fill"
];

static const NSArray* kTabTitlesEN = @[
    @"AIMBOT",
    @"ESP",
    @"MSL",
    @"WEAPONS",
    @"PROFILE"
];

static const NSArray* kTabTitlesPT = @[
    @"FUNÇÕES",
    @"ESP",
    @"EXTRAS",
    @"ARMAS",
    @"PERFIL"
];

static const NSArray* kTabTitlesTH = @[
    @"อาimbOT",
    @"ESP",
    @"MSL",
    @"อาวุธ",
    @"โปรไฟล์"
];

// Feature button tags
static const NSInteger kFeatureButtonBaseTag = 88800;
static const NSInteger kGhostButtonTag = 88801;
static const NSInteger kTeleVIPButtonTag = 88802;
static const NSInteger kUndergroundButtonTag = 88803;
static const NSInteger kAITelekillButtonTag = 88804;
static const NSInteger kNinjaRunButtonTag = 88805;
static const NSInteger kFlyAlturaButtonTag = 88806;
static const NSInteger kFlyNormalButtonTag = 88807;
static const NSInteger kSavePosButtonTag = 88808;
static const NSInteger kClearAntiuButtonTag = 88809;
static const NSInteger kMagnetKillButtonTag = 88810;

// Screen metrics
#define kScreenWidth  [UIScreen mainScreen].bounds.size.width
#define kScreenHeight [UIScreen mainScreen].bounds.size.height
#define kScreenScale  [UIScreen mainScreen].scale

#endif /* UIConstants_h */
