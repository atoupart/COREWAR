.name 		"turtle"
.comment "TURTLE FFS U LAMA"

	sti			r1, %:zork, %1
	sti			r1, %:ardef, %1
	sti			r1, %:avdef, %1
	sti			r1, %:entry_l1, %1
	ld			%0, r16
	fork		%:zork

