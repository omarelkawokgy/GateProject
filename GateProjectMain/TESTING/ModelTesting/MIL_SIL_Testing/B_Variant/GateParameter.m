addpath('..\..\..\..\SRC');

%Verification states%
OPENING_ACTIVE = uint8(1);
WRONG_PASSWORD = uint8(2);
PASSWORD_VERIFIED = uint8(5);
NO_PASS_ASSIG = uint8(6);
PASS_ASSIGNED = uint8(7);
PASS_INCOMPLETE = uint8(8);
TIMEOUT = uint8(9);

%Timers%
ONE_SEC = uint16(1000);
OPEN_TIMEOUT = uint32(60*ONE_SEC);
OPEN_SIDE_VALUE = uint16(3*ONE_SEC);
CLOSE_SIDE_VALUE = single(2.95*ONE_SEC);
PASS_TIMEOUT = uint16(10*ONE_SEC);
MOVING_TIMER = uint32(30*ONE_SEC);
STABLE_TIMER_VALUE = uint8(10);


%Current Calib%
CURRENT_STABLE_TIMER = uint8(200);
CURRENT_THRESH = uint16(1000);

%Motor and Gate States%
OPENING = uint8(11);
CLOSED = uint8(12);
CLOSING = uint8(13);
OPEN = uint8(14);
INIT = uint8(15);

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