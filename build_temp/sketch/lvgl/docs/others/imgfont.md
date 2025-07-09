#line 1 "C:\\Users\\chadgroves\\OneDrive - Simventions, Inc\\Desktop\\ShootingAssistant_V4\\lvgl\\docs\\others\\imgfont.md"
# Image font (imgfont)
Draw image in label or span obj with imgfont.
This is often used to display Unicode emoji icons in text.
Supported image formats: determined by LVGL image decoder.

## Usage
Enable `LV_USE_IMGFONT` in `lv_conf.h`.

To create a new imgfont use `lv_imgfont_create(height, path_cb)`.

`height` used to indicate the size of a imgfont.
`path_cb` Used to get the image path of the specified unicode.

Use `lv_imgfont_destroy(imgfont)` to destroy a imgfont that is no longer used.

## Example
```eval_rst
.. include:: ../../examples/others/imgfont/index.rst
```

## API
```eval_rst
.. doxygenfile:: lv_imgfont.h
  :project: lvgl
```
