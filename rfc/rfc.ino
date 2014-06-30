int incomingByte = 0;   // para los datos de entrada serie

void setup()
{
	Serial.begin(9600);   // abre el puerto serie, establece la velocidad a 9600 bps
}

void loop()
{
	if (Serial.available() > 0)
	{
		// lee el byte de entrada:
		incomingByte = Serial.read();

		if (incomingByte == 0xD)
		{
			CustomSerialFlush();
			return;
		}

		Serial.write(incomingByte);

	}
}

void CustomSerialFlush()
{
	while (Serial.available())
		Serial.read();
}

void pb(int b)
{
	// prints value unaltered, i.e. the raw binary version of the
	// byte. The serial monitor interprets all bytes as
	// ASCII, so 33, the first number,  will show up as '!'
	Serial.write(b);

	Serial.print(", dec: ");
	// prints value as string as an ASCII-encoded decimal (base 10).
	// Decimal is the  default format for Serial.print() and Serial.println(),
	// so no modifier is needed:
	Serial.print(b);
	// But you can declare the modifier for decimal if you want to.
	//this also works if you uncomment it:

	// Serial.print(thisByte, DEC);


	Serial.print(", hex: ");
	// prints value as string in hexadecimal (base 16):
	Serial.print(b, HEX);

	Serial.print(", oct: ");
	// prints value as string in octal (base 8);
	Serial.print(b, OCT);

	Serial.print(", bin: ");
	// prints value as string in binary (base 2)
	// also prints ending line break:
	Serial.println(b, BIN);
}

