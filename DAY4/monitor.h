#pragma once

class Monitor
{
	int brightness = 80;
	int resolution = 1280;
public:
	int get_resolution() const { return resolution; }
	int get_brightness() const { return brightness; }

	void set_resolution(int value) { resolution = value; }
	void set_brightness(int value) { brightness = value; }
};