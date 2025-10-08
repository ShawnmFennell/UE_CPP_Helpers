// Copyright [Your Name/Company]. All Rights Reserved.
//
// DebugMacros.h
// Collection of debug helper macros for logging and drawing in Unreal Engine
//
// Usage:
//   #include "DebugMacros.h"
//   
//   DEBUG_SCREEN("Hello World");
//   DEBUG_SCREENF("Health: %d", Health);
//   DEBUG_SPHERE(GetActorLocation(), 50.f);
//   DEBUG_LINE_PERSIST(Start, End);
#pragma once
#include "CoreMinimal.h"
#include "DrawDebugHelpers.h"

// ============================================================================
// DEBUG LOGGING MACROS // TEXT IS AN UNREAL SPECIFIC MACRO. NOT PART OF C++ STANDARD LIBRARY
// FString is Unreal specific string type.
// ============================================================================

#if UE_BUILD_DEBUG || UE_BUILD_DEVELOPMENT

// Boolean formatting helper
#define BOOL_TO_STR(bValue) (bValue ? TEXT("true") : TEXT("false"))

// Screen debug messages
#define DEBUG_SCREEN(Message) if(GEngine) GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::White, TEXT(Message))
#define DEBUG_SCREEN_C(Message, Color) if(GEngine) GEngine->AddOnScreenDebugMessage(-1, 5.f, Color, TEXT(Message))
#define DEBUG_SCREEN_T(Message, Time) if(GEngine) GEngine->AddOnScreenDebugMessage(-1, Time, FColor::White, TEXT(Message))
#define DEBUG_SCREEN_TC(Message, Time, Color) if(GEngine) GEngine->AddOnScreenDebugMessage(-1, Time, Color, TEXT(Message))

// Screen debug for single frame (duration = 0)
#define DEBUG_SCREEN_1FRAME(Message) if(GEngine) GEngine->AddOnScreenDebugMessage(-1, 0.0f, FColor::White, TEXT(Message))
#define DEBUG_SCREEN_1FRAME_C(Message, Color) if(GEngine) GEngine->AddOnScreenDebugMessage(-1, 0.0f, Color, TEXT(Message))

// Screen debug that updates in place using a key (perfect for Tick() or values that change every frame)
// Key Assignment Convention (suggested):
//   0-9:   Player stats (health, speed, position, etc.)
//   10-19: Game state info
//   20-29: AI/Enemy info
//   30-39: Network/multiplayer info
#define DEBUG_SCREEN_KEY(Key, Message) if(GEngine) GEngine->AddOnScreenDebugMessage(Key, 0.0f, FColor::White, TEXT(Message))
#define DEBUG_SCREEN_KEY_C(Key, Message, Color) if(GEngine) GEngine->AddOnScreenDebugMessage(Key, 0.0f, Color, TEXT(Message))

// Screen debug with formatted strings
#define DEBUG_SCREENF(Format, ...) if(GEngine) GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::White, FString::Printf(TEXT(Format), ##__VA_ARGS__))
#define DEBUG_SCREENF_C(Color, Format, ...) if(GEngine) GEngine->AddOnScreenDebugMessage(-1, 5.f, Color, FString::Printf(TEXT(Format), ##__VA_ARGS__))
#define DEBUG_SCREEN_BOOL(Message, BoolValue) if (GEngine) GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::White, FString::Printf(TEXT("%s: %s"), TEXT(Message), BoolValue ? TEXT("true") : TEXT("false")))
#define DEBUG_SCREEN_BOOL_C(Message, BoolValue, Color) if (GEngine) GEngine->AddOnScreenDebugMessage(-1, 5.0f, Color, FString::Printf(TEXT("%s: %s"), TEXT(Message), BoolValue ? TEXT("true") : TEXT("false")))

// Screen debug with formatted strings for single frame (duration = 0)
#define DEBUG_SCREEN_BOOL_1FRAME(Message, BoolValue) if (GEngine) GEngine->AddOnScreenDebugMessage(-1, 0.0f, FColor::White, FString::Printf(TEXT("%s: %s"), TEXT(Message), BoolValue ? TEXT("true") : TEXT("false")))

// Formatted version for updating values
#define DEBUG_SCREEN_KEYF(Key, Format, ...) if(GEngine) GEngine->AddOnScreenDebugMessage(Key, 0.0f, FColor::White, FString::Printf(TEXT(Format), ##__VA_ARGS__))
#define DEBUG_SCREEN_KEYF_C(Key, Color, Format, ...) if(GEngine) GEngine->AddOnScreenDebugMessage(Key, 0.0f, Color, FString::Printf(TEXT(Format), ##__VA_ARGS__))

// Output log messages
#define DEBUG_LOG(Message) UE_LOG(LogTemp, Warning, TEXT("%s"), *FString(Message))
#define DEBUG_LOGF(Format, ...) UE_LOG(LogTemp, Warning, TEXT(Format), ##__VA_ARGS__)

// Warning and error logs
#define DEBUG_WARNING(Message) UE_LOG(LogTemp, Warning, TEXT("%s"), *FString(Message))
#define DEBUG_ERROR(Message) UE_LOG(LogTemp, Error, TEXT("%s"), *FString(Message))
#define DEBUG_WARNINGF(Format, ...) UE_LOG(LogTemp, Warning, TEXT(Format), ##__VA_ARGS__)
#define DEBUG_ERRORF(Format, ...) UE_LOG(LogTemp, Error, TEXT(Format), ##__VA_ARGS__)

// ============================================================================
// DEBUG DRAW MACROS
// ============================================================================

// Draw debug sphere
#define DEBUG_SPHERE(Location, Radius) DrawDebugSphere(GetWorld(), Location, Radius, 12, FColor::Red, false, 2.f)
#define DEBUG_SPHERE_C(Location, Radius, Color) DrawDebugSphere(GetWorld(), Location, Radius, 12, Color, false, 2.f)
#define DEBUG_SPHERE_PERSIST(Location, Radius) DrawDebugSphere(GetWorld(), Location, Radius, 12, FColor::Red, true, -1.f)
#define DEBUG_SPHERE_T(Location, Radius, Time) DrawDebugSphere(GetWorld(), Location, Radius, 12, FColor::Red, false, Time)
#define DEBUG_SPHERE_FULL(Location, Radius, Color, Time) DrawDebugSphere(GetWorld(), Location, Radius, 12, Color, false, Time)

// Draw debug capsule
#define DEBUG_CAPSULE(Center, HalfHeight, Radius) DrawDebugCapsule(GetWorld(), Center, HalfHeight, Radius, FQuat::Identity, FColor::Red, false, 2.f)
#define DEBUG_CAPSULE_C(Center, HalfHeight, Radius, Color) DrawDebugCapsule(GetWorld(), Center, HalfHeight, Radius, FQuat::Identity, Color, false, 2.f)

// Draw debug box
#define DEBUG_BOX(Center, Extent) DrawDebugBox(GetWorld(), Center, Extent, FColor::Red, false, 2.f)
#define DEBUG_BOX_C(Center, Extent, Color) DrawDebugBox(GetWorld(), Center, Extent, Color, false, 2.f)
#define DEBUG_BOX_T(Center, Extent, Time) DrawDebugBox(GetWorld(), Center, Extent, FColor::Red, false, Time)

// Draw debug line
#define DEBUG_LINE(Start, End) DrawDebugLine(GetWorld(), Start, End, FColor::Red, false, 2.f, 0, 1.f)
#define DEBUG_LINE_C(Start, End, Color) DrawDebugLine(GetWorld(), Start, End, Color, false, 2.f, 0, 1.f)
#define DEBUG_LINE_T(Start, End, Time) DrawDebugLine(GetWorld(), Start, End, FColor::Red, false, Time, 0, 1.f)
#define DEBUG_LINE_FULL(Start, End, Color, Time, Thickness) DrawDebugLine(GetWorld(), Start, End, Color, false, Time, 0, Thickness)
#define DEBUG_LINE_PERSIST(Start, End) DrawDebugLine(GetWorld(), Start, End, FColor::Red, true, -1.f, 0, 2.f)
#define DEBUG_LINE_PERSIST_C(Start, End, Color) DrawDebugLine(GetWorld(), Start, End, Color, true, -1.f, 0, 2.f)

// Draw debug point
#define DEBUG_POINT(Location) DrawDebugPoint(GetWorld(), Location, 10.f, FColor::Red, false, 2.f)
#define DEBUG_POINT_C(Location, Color) DrawDebugPoint(GetWorld(), Location, 10.f, Color, false, 2.f)
#define DEBUG_POINT_T(Location, Time) DrawDebugPoint(GetWorld(), Location, 10.f, FColor::Red, false, Time)
#define DEBUG_POINT_PERSIST(Location) DrawDebugPoint(GetWorld(), Location, 15.f, FColor::Red, true, -1.f)
#define DEBUG_POINT_PERSIST_C(Location, Color) DrawDebugPoint(GetWorld(), Location, 15.f, Color, true, -1.f)

// Draw debug vector (line + point at end)
#define DEBUG_VECTOR(Start, End) if(GetWorld()) {DrawDebugLine(GetWorld(), Start, End, FColor::Red, false, 2.f, 0, 2.f); DrawDebugPoint(GetWorld(), End, 15.f, FColor::Red, false, 2.f);}
#define DEBUG_VECTOR_C(Start, End, Color) if(GetWorld()) {DrawDebugLine(GetWorld(), Start, End, Color, false, 2.f, 0, 2.f); DrawDebugPoint(GetWorld(), End, 15.f, Color, false, 2.f);}
#define DEBUG_VECTOR_PERSIST(Start, End) if(GetWorld()) {DrawDebugLine(GetWorld(), Start, End, FColor::Red, true, -1.f, 0, 2.f); DrawDebugPoint(GetWorld(), End, 15.f, FColor::Red, true, -1.f);}

// Draw debug arrow
#define DEBUG_ARROW(Start, End) DrawDebugDirectionalArrow(GetWorld(), Start, End, 50.f, FColor::Red, false, 2.f, 0, 2.f)
#define DEBUG_ARROW_C(Start, End, Color) DrawDebugDirectionalArrow(GetWorld(), Start, End, 50.f, Color, false, 2.f, 0, 2.f)

#else
// Shipping Build Macros
#endif

// ============================================================================
// CONDITIONAL DEBUG MACROS (Only in Debug/Development builds)
// ============================================================================
/* Usage Examples
 * DEBUG_ONLY(int DebugCounter = 0;)
 * DEBUG_ONLY(LogPlayerPosition();)
 * DEBUG_ONLY({
 *	FVector Location = GetActorLocation();
 *	DrawDebugSphere(GetWorld(), Location, 100.f, 12, FColor::Red);
 *	UE_LOG(LogTemp, Warning, TEXT("Position: %s"), *Location.ToString());})
 */
#if UE_BUILD_DEBUG || UE_BUILD_DEVELOPMENT
    #define DEBUG_ONLY(Code) Code
#else
    #define DEBUG_ONLY(Code)
#endif

// ============================================================================
// COMMON COLOR DEFINITIONS
// ============================================================================

namespace DebugColor
{
    const FColor Red = FColor::Red;
    const FColor Green = FColor::Green;
    const FColor Blue = FColor::Blue;
    const FColor Yellow = FColor::Yellow;
    const FColor Cyan = FColor::Cyan;
    const FColor Magenta = FColor::Magenta;
    const FColor White = FColor::White;
    const FColor Black = FColor::Black;
    const FColor Orange = FColor::Orange;
    const FColor Purple = FColor::Purple;
}

// ============================================================================
// End of DebugMacros.h
// ============================================================================