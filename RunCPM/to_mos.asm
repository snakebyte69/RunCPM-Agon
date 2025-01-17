; to_mos.asm
; CP/M program to send a message to the MOS and receive feedback

	org 0x100

start:
	ld de, message
	call MOS_send
	ld a, 'M'
	call print_char
	ld a, 'O'
	call print_char
	ld a, 'S'
	call print_char
	ld a, ':'
	call print_char
	ld a, ' '
	call print_char
	call MOS_receive
	call print_char
	ret

print_char:
	ld c, 2
	call 5
	ret

MOS_send:
	ld c, 9
	call 5
	ret

MOS_receive:
	ld c, 8
	call 5
	ret

message:
	db 'Hello', 0
