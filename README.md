# Knob: ESPHome HomeAssistant display

This is a project to build a smart home display for ESP32 devices using ESPHome & Home Assistant.
Currently testing using an Elecrow 2.1 inch 480px circular display featuring rotary dial, press & touchscreen inputs.

For future versions ideally the hardware layer (page) should be abstracted away to support multiple devices with different sensors, inputs and resolutions.
Ideally you should be able to select which entities you would like to show from your home assistant or during first time setup, but for now string replacements with entity id's will do.
I'd like to keep everything in ESPHome LVGL yaml as much as possible, avoiding python or C libraries due to hardware performance.


## Features
- Manual navigation through pages using double press to open the menu and selecting a page using single press
- Wake the display on input or motion if supported
- Automatic dimming and turning off the display after a delay
- Wake the display from home assistant automation and show a selected page (or custom notification text/image if possible)


## Entity pages
The following entity types should be supported:
- Lights: A page showing a lamp or light group showing the current state (off/on), brightness (if supported) and color (if supported).
  - Rotate the dial to change brightness shown as an arc on the display
  - Single press to turn the lamp on/off shown by a lamp icon
- Clock: Default page showing the current time and timer state
  - Single press to start/stop the timer shown on the clock face
  - Open the Timer menu page to adjust the duration
  - Play a sound (if supported) and show a flashing icon when the timer ends
- Weather: Separate menu page showing the hourly/daily forecast
- Climate: A page showing a climate entity (radiator dial/aiconditioner)
  - Rotate the dial to change the desired temperature setting shown as an arc on the display
  - Single press to turn the climate device on/off shown by an icon
  - Select Fan speed and HVAC mode using the touch screen if supported
- Music: A page showing a media_player entity's current state (off / media title, track position & album art if available)
  - Rotate the dial to change the volume shown by an arc on the display
  - Single press to play/pause
  - Previous/next song buttons on the touchscreen
- Camera: A page showing the live view (or snapshot if not supported) of a camera entity
- Calendar: A page showing the next upcoming event(s) on one or multiple calendar entities
- Todo: A page showing a todo list entity
  - Rotate the dial to highlight a todo-item, and mark it as done/not done on single press
- Energy: A page showing the current energy price & usage
- Alarm: A page showing an alarm entity and its current state

