%Verification states%
OPENING_ACTIVE = uint8(1);
WRONG_PASSWORD = uint8(2);
PASSWORD_VERIFIED = uint8(5);
NO_PASS_ASSIG = uint8(6);
PASS_ASSIGNED = uint8(7);
PASS_INCOMPLETE = uint8(8);
TIMEOUT = uint8(9);

%Timers%
oneSec = uint16(1000);
OPEN_TIMEOUT = uint32(60*oneSec);
OPEN_SIDE_VALUE = uint16(3*oneSec);
CLOSE_SIDE_VALUE = single(2.95*oneSec);
PASS_TIMEOUT = uint16(10*oneSec);

%Motor States%
OPENING = uint8(11);
CLOSED = uint8(12);
CLOSING = uint8(13);
OPEN = uint8(14);

%Keypad Char ASCII%
CHAR0 = uint8(48);
CHAR1 = uint8(49);
CHAR2 = uint8(50);
CHAR3 = uint8(51);
CHAR4 = uint8(52);
CHAR5 = uint8(53);
CHAR6 = uint8(54);
CHAR7 = uint8(55);
CHAR8 = uint8(56);
CHAR9 = uint8(57);
CHAR_STAR = uint8(42);
CHAR_HASH = uint8(35);

OPEN_CHAR = CHAR_HASH;
CLOSE_CHAR = CHAR_STAR;