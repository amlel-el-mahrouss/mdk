/*
 * Created on Fri May 10 2024
 *
 * Copyright (c) 2024 SystemLabs B.V
 */

#include <MLCoreGraphicsContext.hxx>
#include <MLCoreGraphicsContextCairo.inl>

/// @brief Request a context regarding the features set.
/// @param featureSet the feature set.
/// @param strict should we require all the features to be here?
/// @note if no, please check for feature with operator& inside MLCoreGraphicsContext.
/// @return The new graphics context.
ML_IMPORT MLCoreGraphicsContext* CGRequestContext(CGSizeT featureSet, bool strict)
{
    MLCoreGraphicsContext* context = new MLCoreGraphicsContextCairo();
    return context;
}

/// @brief Releases a Core Graphics context.
/// @param context The context itself.
/// @return This function returns void.
ML_IMPORT void CGReleaseContext(MLCoreGraphicsContext* context)
{
    if (context)
    {
        delete context;
    }
}