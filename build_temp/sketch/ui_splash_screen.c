#line 1 "C:\\Users\\chadgroves\\OneDrive - Simventions, Inc\\Desktop\\ShootingAssistant_V4\\ui_splash_screen.c"
#include "ui_splash_screen.h"
#include "ui.h"
#include "ui_helpers.h"
#include "ui_modern_options.h"

///////////////////// VARIABLES ////////////////////

lv_obj_t *ui_SplashScreen;
lv_obj_t *ui_SplashBackground;
lv_obj_t *ui_CrosshairContainer;
lv_obj_t *ui_CrosshairCircle;
lv_obj_t *ui_CrosshairVertical;
lv_obj_t *ui_CrosshairHorizontal;
lv_obj_t *ui_BubbleLevelIcon;
lv_obj_t *ui_BubbleBall;
lv_obj_t *ui_SplashTitle;
lv_obj_t *ui_SplashSubtitle;
lv_obj_t *ui_SplashProgressBar;
lv_obj_t *ui_SplashProgressTrack;
lv_obj_t *ui_SplashVersion;

static lv_timer_t *splash_timer = NULL;

///////////////////// ANIMATIONS ////////////////////

static void ui_splash_progress_anim_cb(void *var, int32_t val)
{
    lv_obj_set_width((lv_obj_t *)var, val);
}

///////////////////// FUNCTIONS ////////////////////

void ui_splash_screen_init(void)
{
    // Create main splash screen
    ui_SplashScreen = lv_obj_create(NULL);
    lv_obj_clear_flag(ui_SplashScreen, LV_OBJ_FLAG_SCROLLABLE);

    // Set DEADEYE olive green background with gradient
    lv_obj_set_style_bg_color(ui_SplashScreen, DEADEYE_OLIVE_GREEN, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_color(ui_SplashScreen, DEADEYE_DARK_OLIVE, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui_SplashScreen, LV_GRAD_DIR_VER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_SplashScreen, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    // Crosshair Container
    ui_CrosshairContainer = lv_obj_create(ui_SplashScreen);
    lv_obj_set_width(ui_CrosshairContainer, 120);
    lv_obj_set_height(ui_CrosshairContainer, 120);
    lv_obj_set_align(ui_CrosshairContainer, LV_ALIGN_CENTER);
    lv_obj_set_y(ui_CrosshairContainer, -30);
    lv_obj_clear_flag(ui_CrosshairContainer, LV_OBJ_FLAG_SCROLLABLE);
    lv_obj_set_style_bg_opa(ui_CrosshairContainer, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_CrosshairContainer, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    // Crosshair Circle
    ui_CrosshairCircle = lv_obj_create(ui_CrosshairContainer);
    lv_obj_set_width(ui_CrosshairCircle, 100);
    lv_obj_set_height(ui_CrosshairCircle, 100);
    lv_obj_set_align(ui_CrosshairCircle, LV_ALIGN_CENTER);
    lv_obj_clear_flag(ui_CrosshairCircle, LV_OBJ_FLAG_SCROLLABLE);
    lv_obj_set_style_bg_opa(ui_CrosshairCircle, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_CrosshairCircle, DEADEYE_CROSSHAIR_BROWN, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_CrosshairCircle, 4, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_CrosshairCircle, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui_CrosshairCircle, LV_RADIUS_CIRCLE, LV_PART_MAIN | LV_STATE_DEFAULT);

    // Crosshair Vertical Line
    ui_CrosshairVertical = lv_obj_create(ui_CrosshairContainer);
    lv_obj_set_width(ui_CrosshairVertical, 2);
    lv_obj_set_height(ui_CrosshairVertical, 140);
    lv_obj_set_align(ui_CrosshairVertical, LV_ALIGN_CENTER);
    lv_obj_clear_flag(ui_CrosshairVertical, LV_OBJ_FLAG_SCROLLABLE);
    lv_obj_set_style_bg_color(ui_CrosshairVertical, DEADEYE_CROSSHAIR_BROWN, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_CrosshairVertical, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_CrosshairVertical, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    // Crosshair Horizontal Line
    ui_CrosshairHorizontal = lv_obj_create(ui_CrosshairContainer);
    lv_obj_set_width(ui_CrosshairHorizontal, 140);
    lv_obj_set_height(ui_CrosshairHorizontal, 2);
    lv_obj_set_align(ui_CrosshairHorizontal, LV_ALIGN_CENTER);
    lv_obj_clear_flag(ui_CrosshairHorizontal, LV_OBJ_FLAG_SCROLLABLE);
    lv_obj_set_style_bg_color(ui_CrosshairHorizontal, DEADEYE_CROSSHAIR_BROWN, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_CrosshairHorizontal, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_CrosshairHorizontal, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    // Bubble Level Icon
    ui_BubbleLevelIcon = lv_obj_create(ui_CrosshairContainer);
    lv_obj_set_width(ui_BubbleLevelIcon, 60);
    lv_obj_set_height(ui_BubbleLevelIcon, 20);
    lv_obj_set_align(ui_BubbleLevelIcon, LV_ALIGN_CENTER);
    lv_obj_clear_flag(ui_BubbleLevelIcon, LV_OBJ_FLAG_SCROLLABLE);
    lv_obj_set_style_bg_color(ui_BubbleLevelIcon, DEADEYE_CROSSHAIR_BROWN, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_BubbleLevelIcon, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_BubbleLevelIcon, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui_BubbleLevelIcon, 10, LV_PART_MAIN | LV_STATE_DEFAULT);

    // Bubble Ball
    ui_BubbleBall = lv_obj_create(ui_BubbleLevelIcon);
    lv_obj_set_width(ui_BubbleBall, 16);
    lv_obj_set_height(ui_BubbleBall, 16);
    lv_obj_set_align(ui_BubbleBall, LV_ALIGN_CENTER);
    lv_obj_clear_flag(ui_BubbleBall, LV_OBJ_FLAG_SCROLLABLE);
    lv_obj_set_style_bg_color(ui_BubbleBall, lv_color_hex(0xFF6B35), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_BubbleBall, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_BubbleBall, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui_BubbleBall, LV_RADIUS_CIRCLE, LV_PART_MAIN | LV_STATE_DEFAULT);

    // DEADEYE Title
    ui_SplashTitle = lv_label_create(ui_SplashScreen);
    lv_obj_set_width(ui_SplashTitle, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_SplashTitle, LV_SIZE_CONTENT);
    lv_obj_set_align(ui_SplashTitle, LV_ALIGN_CENTER);
    lv_obj_set_y(ui_SplashTitle, 40);
    lv_label_set_text(ui_SplashTitle, "DEADEYE");
    lv_obj_set_style_text_color(ui_SplashTitle, DEADEYE_CROSSHAIR_BROWN, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_SplashTitle, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_SplashTitle, &lv_font_montserrat_24, LV_PART_MAIN | LV_STATE_DEFAULT);

    // Subtitle
    ui_SplashSubtitle = lv_label_create(ui_SplashScreen);
    lv_obj_set_width(ui_SplashSubtitle, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_SplashSubtitle, LV_SIZE_CONTENT);
    lv_obj_set_align(ui_SplashSubtitle, LV_ALIGN_CENTER);
    lv_obj_set_y(ui_SplashSubtitle, 65);
    lv_label_set_text(ui_SplashSubtitle, "SHOOTING ASSISTANT");
    lv_obj_set_style_text_color(ui_SplashSubtitle, DEADEYE_CROSSHAIR_BROWN, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_SplashSubtitle, 200, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_SplashSubtitle, &lv_font_montserrat_14, LV_PART_MAIN | LV_STATE_DEFAULT);

    // Progress Bar Track
    ui_SplashProgressTrack = lv_obj_create(ui_SplashScreen);
    lv_obj_set_width(ui_SplashProgressTrack, 150);
    lv_obj_set_height(ui_SplashProgressTrack, 4);
    lv_obj_set_align(ui_SplashProgressTrack, LV_ALIGN_CENTER);
    lv_obj_set_y(ui_SplashProgressTrack, 100);
    lv_obj_clear_flag(ui_SplashProgressTrack, LV_OBJ_FLAG_SCROLLABLE);
    lv_obj_set_style_bg_color(ui_SplashProgressTrack, DEADEYE_CROSSHAIR_BROWN, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_SplashProgressTrack, 100, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_SplashProgressTrack, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui_SplashProgressTrack, 2, LV_PART_MAIN | LV_STATE_DEFAULT);

    // Progress Bar
    ui_SplashProgressBar = lv_obj_create(ui_SplashProgressTrack);
    lv_obj_set_width(ui_SplashProgressBar, 0);
    lv_obj_set_height(ui_SplashProgressBar, 4);
    lv_obj_set_align(ui_SplashProgressBar, LV_ALIGN_LEFT_MID);
    lv_obj_clear_flag(ui_SplashProgressBar, LV_OBJ_FLAG_SCROLLABLE);
    lv_obj_set_style_bg_color(ui_SplashProgressBar, lv_color_hex(0xFF6B35), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_color(ui_SplashProgressBar, lv_color_hex(0xFF8A5C), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui_SplashProgressBar, LV_GRAD_DIR_HOR, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_SplashProgressBar, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_SplashProgressBar, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui_SplashProgressBar, 2, LV_PART_MAIN | LV_STATE_DEFAULT);

    // Version Label
    ui_SplashVersion = lv_label_create(ui_SplashScreen);
    lv_obj_set_width(ui_SplashVersion, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_SplashVersion, LV_SIZE_CONTENT);
    lv_obj_set_align(ui_SplashVersion, LV_ALIGN_BOTTOM_MID);
    lv_obj_set_y(ui_SplashVersion, -20);
    lv_label_set_text(ui_SplashVersion, "V2.0 - Precision Tools");
    lv_obj_set_style_text_color(ui_SplashVersion, DEADEYE_CROSSHAIR_BROWN, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_SplashVersion, 150, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_SplashVersion, &lv_font_montserrat_10, LV_PART_MAIN | LV_STATE_DEFAULT);
}

void ui_splash_start_animation(void)
{
    // Create progress bar animation
    lv_anim_t a;
    lv_anim_init(&a);
    lv_anim_set_var(&a, ui_SplashProgressBar);
    lv_anim_set_values(&a, 0, 150);
    lv_anim_set_time(&a, 2000);
    lv_anim_set_delay(&a, 500);
    lv_anim_set_exec_cb(&a, ui_splash_progress_anim_cb);
    lv_anim_set_path_cb(&a, lv_anim_path_ease_out);
    lv_anim_start(&a);

    // Create timer to hide splash screen after 3 seconds
    splash_timer = lv_timer_create(ui_splash_hide_callback, 3000, NULL);
    lv_timer_set_repeat_count(splash_timer, 1);
}

static void ui_splash_fade_ready_cb(lv_anim_t *a)
{
    // Load modern main screen after fade out
    lv_disp_load_scr(ui_OptionsPage_Modern);
    // Clean up splash screen
    lv_obj_del(ui_SplashScreen);
}

void ui_splash_hide_callback(lv_timer_t *timer)
{
    // Create fade out animation
    lv_anim_t fade_anim;
    lv_anim_init(&fade_anim);
    lv_anim_set_var(&fade_anim, ui_SplashScreen);
    lv_anim_set_values(&fade_anim, 255, 0);
    lv_anim_set_time(&fade_anim, 500);
    lv_anim_set_exec_cb(&fade_anim, (lv_anim_exec_xcb_t)lv_obj_set_style_opa);
    lv_anim_set_ready_cb(&fade_anim, ui_splash_fade_ready_cb);
    lv_anim_start(&fade_anim);

    // Clean up timer
    splash_timer = NULL;
}

void ui_splash_screen_destroy(void)
{
    if (splash_timer)
    {
        lv_timer_del(splash_timer);
        splash_timer = NULL;
    }
    if (ui_SplashScreen)
    {
        lv_obj_del(ui_SplashScreen);
        ui_SplashScreen = NULL;
    }
}
