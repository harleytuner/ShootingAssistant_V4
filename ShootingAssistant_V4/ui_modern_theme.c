// Modern UI Theme System Implementation
// Creates a premium, consumer-grade appearance

#include "ui_modern_theme.h"
#include <string.h>

// Global theme instances
ui_modern_colors_t ui_modern_colors;
ui_modern_design_t ui_modern_design;

// Theme initialization
void ui_modern_theme_init(void)
{
    // Initialize DEADEYE military olive color palette
    ui_modern_colors.primary_dark = lv_color_hex(0x1A1B0F);   // Deep olive dark
    ui_modern_colors.primary_medium = lv_color_hex(0x2D2E1F); // Military olive medium
    ui_modern_colors.primary_light = lv_color_hex(0x3F4133);  // Olive light

    ui_modern_colors.accent_orange = lv_color_hex(0xD4AF37); // Military gold
    ui_modern_colors.accent_blue = lv_color_hex(0x4A5D23);   // Dark olive green
    ui_modern_colors.accent_green = lv_color_hex(0x8B7355);  // Tactical brown
    ui_modern_colors.accent_red = lv_color_hex(0x8B0000);    // Dark red
    ui_modern_colors.accent_purple = lv_color_hex(0x5D4037); // Brown accent

    ui_modern_colors.text_primary = lv_color_hex(0xE8E6E3);   // Light sand
    ui_modern_colors.text_secondary = lv_color_hex(0xCDCAAA); // Muted sand
    ui_modern_colors.text_muted = lv_color_hex(0x9C9A7A);     // Olive muted

    ui_modern_colors.glass_overlay = lv_color_hex(0x2A2B1C); // Dark olive overlay
    ui_modern_colors.neon_glow = lv_color_hex(0xD4AF37);     // Gold glow
    ui_modern_colors.warning_amber = lv_color_hex(0xDAA520); // Golden amber

    // Initialize design system
    ui_modern_design.radius_small = 4;
    ui_modern_design.radius_medium = 8;
    ui_modern_design.radius_large = 16;
    ui_modern_design.radius_pill = 25;

    ui_modern_design.shadow_small = 2;
    ui_modern_design.shadow_medium = 4;
    ui_modern_design.shadow_large = 8;

    ui_modern_design.spacing_xs = 4;
    ui_modern_design.spacing_sm = 8;
    ui_modern_design.spacing_md = 16;
    ui_modern_design.spacing_lg = 24;
    ui_modern_design.spacing_xl = 32;

    ui_modern_design.anim_fast = 200;
    ui_modern_design.anim_medium = 300;
    ui_modern_design.anim_slow = 500;
}

// Modern page styling
void ui_modern_style_page(lv_obj_t *page)
{
    // Dark gradient background
    lv_obj_set_style_bg_color(page, ui_modern_colors.primary_dark, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_color(page, ui_modern_colors.primary_medium, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(page, LV_GRAD_DIR_VER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(page, LV_OPA_100, LV_PART_MAIN | LV_STATE_DEFAULT);

    // Remove default padding
    lv_obj_set_style_pad_all(page, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(page, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
}

// Primary button styling (main action buttons)
void ui_modern_style_button_primary(lv_obj_t *btn)
{
    // Normal state
    lv_obj_set_style_bg_color(btn, ui_modern_colors.accent_orange, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_color(btn, lv_color_hex(0xFF8A5C), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(btn, LV_GRAD_DIR_VER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(btn, LV_OPA_100, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_set_style_border_width(btn, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(btn, ui_modern_design.radius_medium, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(btn, ui_modern_design.shadow_medium, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_color(btn, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_opa(btn, LV_OPA_50, LV_PART_MAIN | LV_STATE_DEFAULT);

    // Text styling
    lv_obj_set_style_text_color(btn, ui_modern_colors.text_primary, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(btn, &lv_font_montserrat_14, LV_PART_MAIN | LV_STATE_DEFAULT);

    // Pressed state
    lv_obj_set_style_bg_color(btn, lv_color_hex(0xE55A2B), LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_transform_width(btn, -2, LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_transform_height(btn, -2, LV_PART_MAIN | LV_STATE_PRESSED);

    // Padding
    lv_obj_set_style_pad_ver(btn, ui_modern_design.spacing_sm, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_hor(btn, ui_modern_design.spacing_md, LV_PART_MAIN | LV_STATE_DEFAULT);
}

// Secondary button styling
void ui_modern_style_button_secondary(lv_obj_t *btn)
{
    // Glass-like appearance
    lv_obj_set_style_bg_color(btn, ui_modern_colors.glass_overlay, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(btn, LV_OPA_40, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_set_style_border_width(btn, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(btn, ui_modern_colors.text_secondary, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(btn, LV_OPA_30, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(btn, ui_modern_design.radius_medium, LV_PART_MAIN | LV_STATE_DEFAULT);

    // Text styling
    lv_obj_set_style_text_color(btn, ui_modern_colors.text_secondary, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(btn, &lv_font_montserrat_14, LV_PART_MAIN | LV_STATE_DEFAULT);

    // Pressed state
    lv_obj_set_style_bg_opa(btn, LV_OPA_70, LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_border_opa(btn, LV_OPA_60, LV_PART_MAIN | LV_STATE_PRESSED);

    // Padding
    lv_obj_set_style_pad_ver(btn, ui_modern_design.spacing_sm, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_hor(btn, ui_modern_design.spacing_md, LV_PART_MAIN | LV_STATE_DEFAULT);
}

// Icon button styling
void ui_modern_style_button_icon(lv_obj_t *btn)
{
    // Circular icon button
    lv_obj_set_style_bg_color(btn, ui_modern_colors.primary_light, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(btn, LV_OPA_80, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(btn, ui_modern_design.radius_pill, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(btn, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    // Icon styling
    lv_obj_set_style_text_color(btn, ui_modern_colors.text_primary, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(btn, &lv_font_montserrat_20, LV_PART_MAIN | LV_STATE_DEFAULT);

    // Pressed effect
    lv_obj_set_style_bg_color(btn, ui_modern_colors.accent_orange, LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_transform_width(btn, -4, LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_transform_height(btn, -4, LV_PART_MAIN | LV_STATE_PRESSED);

    // Padding
    lv_obj_set_style_pad_all(btn, ui_modern_design.spacing_sm, LV_PART_MAIN | LV_STATE_DEFAULT);
}

// Card styling
void ui_modern_style_card(lv_obj_t *card)
{
    // Glass card effect
    lv_obj_set_style_bg_color(card, ui_modern_colors.primary_light, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(card, LV_OPA_60, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(card, ui_modern_design.radius_large, LV_PART_MAIN | LV_STATE_DEFAULT);

    // Subtle border
    lv_obj_set_style_border_width(card, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(card, ui_modern_colors.text_muted, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(card, LV_OPA_20, LV_PART_MAIN | LV_STATE_DEFAULT);

    // Shadow
    lv_obj_set_style_shadow_width(card, ui_modern_design.shadow_large, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_color(card, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_opa(card, LV_OPA_30, LV_PART_MAIN | LV_STATE_DEFAULT);

    // Padding
    lv_obj_set_style_pad_all(card, ui_modern_design.spacing_md, LV_PART_MAIN | LV_STATE_DEFAULT);
}

// Modern slider styling
void ui_modern_style_slider(lv_obj_t *slider)
{
    // Track styling
    lv_obj_set_style_bg_color(slider, ui_modern_colors.primary_light, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(slider, LV_OPA_50, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(slider, ui_modern_design.radius_pill, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(slider, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    // Indicator styling
    lv_obj_set_style_bg_color(slider, ui_modern_colors.accent_orange, LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_color(slider, lv_color_hex(0xFF8A5C), LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(slider, LV_GRAD_DIR_HOR, LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(slider, ui_modern_design.radius_pill, LV_PART_INDICATOR | LV_STATE_DEFAULT);

    // Knob styling
    lv_obj_set_style_bg_color(slider, ui_modern_colors.text_primary, LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(slider, ui_modern_design.radius_pill, LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(slider, 2, LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(slider, ui_modern_colors.accent_orange, LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(slider, ui_modern_design.shadow_small, LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_color(slider, lv_color_hex(0x000000), LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_opa(slider, LV_OPA_50, LV_PART_KNOB | LV_STATE_DEFAULT);

    // Pressed knob
    lv_obj_set_style_transform_width(slider, 4, LV_PART_KNOB | LV_STATE_PRESSED);
    lv_obj_set_style_transform_height(slider, 4, LV_PART_KNOB | LV_STATE_PRESSED);
}

// Title label styling
void ui_modern_style_label_title(lv_obj_t *label)
{
    lv_obj_set_style_text_color(label, ui_modern_colors.text_primary, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(label, &lv_font_montserrat_28, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(label, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
}

// Heading label styling
void ui_modern_style_label_heading(lv_obj_t *label)
{
    lv_obj_set_style_text_color(label, ui_modern_colors.text_primary, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(label, &lv_font_montserrat_20, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(label, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
}

// Body text styling
void ui_modern_style_label_body(lv_obj_t *label)
{
    lv_obj_set_style_text_color(label, ui_modern_colors.text_secondary, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(label, &lv_font_montserrat_14, LV_PART_MAIN | LV_STATE_DEFAULT);
}

// Caption text styling
void ui_modern_style_label_caption(lv_obj_t *label)
{
    lv_obj_set_style_text_color(label, ui_modern_colors.text_muted, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(label, &lv_font_montserrat_12, LV_PART_MAIN | LV_STATE_DEFAULT);
}

// Glass container effect
void ui_modern_style_container_glass(lv_obj_t *cont)
{
    lv_obj_set_style_bg_color(cont, ui_modern_colors.glass_overlay, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(cont, LV_OPA_30, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(cont, ui_modern_design.radius_large, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(cont, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(cont, ui_modern_colors.text_muted, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(cont, LV_OPA_20, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_all(cont, ui_modern_design.spacing_md, LV_PART_MAIN | LV_STATE_DEFAULT);
}

// Navigation bar styling
void ui_modern_style_nav_bar(lv_obj_t *nav)
{
    lv_obj_set_style_bg_color(nav, ui_modern_colors.primary_dark, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(nav, LV_OPA_95, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(nav, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_all(nav, ui_modern_design.spacing_sm, LV_PART_MAIN | LV_STATE_DEFAULT);

    // Add subtle top border
    lv_obj_set_style_border_side(nav, LV_BORDER_SIDE_TOP, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(nav, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(nav, ui_modern_colors.text_muted, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(nav, LV_OPA_20, LV_PART_MAIN | LV_STATE_DEFAULT);
}

// Animation helpers
void ui_modern_fade_in(lv_obj_t *obj, uint16_t duration)
{
    lv_obj_set_style_opa(obj, LV_OPA_TRANSP, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_anim_t a;
    lv_anim_init(&a);
    lv_anim_set_var(&a, obj);
    lv_anim_set_values(&a, LV_OPA_TRANSP, LV_OPA_COVER);
    lv_anim_set_time(&a, duration);
    lv_anim_set_exec_cb(&a, (lv_anim_exec_xcb_t)lv_obj_set_style_opa);
    lv_anim_start(&a);
}

void ui_modern_scale_bounce(lv_obj_t *obj)
{
    lv_anim_t a;
    lv_anim_init(&a);
    lv_anim_set_var(&a, obj);
    lv_anim_set_values(&a, 256, 280);
    lv_anim_set_time(&a, 150);
    lv_anim_set_path_cb(&a, lv_anim_path_bounce);
    lv_anim_set_exec_cb(&a, (lv_anim_exec_xcb_t)lv_obj_set_style_transform_zoom);
    lv_anim_set_repeat_count(&a, 1);
    lv_anim_set_playback_time(&a, 150);
    lv_anim_start(&a);
}
