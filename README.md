## DHT11 usable with DigiUSB

DigiUSB from Digispark for ATTINY85 requires calling DigiUSB.refresh() every N microseconds or it disconnects.

Also, you can't just delay in-progress reading from DHT11 as it will be incorrect.

This code adapts DHT library from Adafruit to try and overcome this with more careful timings & added DigiUSB.refresh() all over the place.

## License

(c) 2015 Gleb Tv
MIT License