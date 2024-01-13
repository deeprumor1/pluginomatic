import("music.lib");


process = vgroup("Gain Effect", hslider("Gain", 1, 0, 10, 0.01) * _);