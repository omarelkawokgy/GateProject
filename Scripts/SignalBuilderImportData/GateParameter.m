%Verification states%
OPENING_ACTIVE = 1;
WRONG_PASSWORD =2;
PASSWORD_VERIFIED = 5;
NO_PASS_ASSIG = 6;
PASS_ASSIGNED = 7;
PASS_INCOMPLETE = 8;
TIMEOUT = 9;

%Timers%
oneSec = 1000;
OPEN_TIMEOUT = 60*oneSec;
OPEN_SIDE_VALUE = 3*oneSec;
CLOSE_SIDE_VALUE = 2.95*oneSec;
PASS_TIMEOUT = 10*oneSec;

%Motor States%
OPENING = 11;
CLOSED = 12;
CLOSING = 13;
OPEN = 14;

%Keypad Char ASCII%
CHAR0 = 48;
CHAR1 = 49;
CHAR2 = 50;
CHAR3 = 51;
CHAR4 = 52;
CHAR5 = 53;
CHAR6 = 54;
CHAR7 = 55;
CHAR8 = 56;
CHAR9 = 57;
CHAR_STAR = 42;
CHAR_HASH = 35;

OPEN_CHAR = CHAR_HASH;
CLOSE_CHAR = CHAR_STAR;