# Neopixel Ring to display temperature with Arduino

## Serial control

The arduino receives temperature in °C through serial.

The serial command to control it:

```
0,20; // for 20 °C
```

The first '0' is constant. The next number is the tempetature.

If the temperature is less than MIN_TEMP, the LEDs blink in blue. They blink in red if the temperature is more than MAX_TEMP.

For exemple : 

80 °C

```

0,80;

```

-1 °C

```

0,-1;

```

30 °C

```

0,30;

