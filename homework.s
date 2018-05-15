.data

.balign 4
message1: .asciz "Input a first number : "

.balign 4
message2: .asciz "Input a second number : "

.balign 4
message3: .asciz "First number is %d, Second number is %d\n"

.balign 4
message_add: .asciz "%d + %d = %d\n"

.balign 4
message_sub: .asciz "%d - %d = %d\n"

.balign 4
message_mul: .asciz "%d * %d = %d\n"

.balign 4
message_div: .asciz "%d / %d = %d\n"

.balign 4
message_error: .asciz "ERROR\n ERROR CODE = %d\n"

.balign 4
scan_pattern: .asciz "%d"

.balign 4
number_read1: .word 0

.balign 4
number_read2: .word 0

.balign 4
return: .word 0

.balign 4
return2: .word 0







.text

add:
  ldr r4, addr_of_return2
  str lr , [r4]

  add r3, r1, r2
  ldr r0, addr_of_message_add
  bl printf  

  ldr lr, addr_of_return2
  ldr lr, [lr]
  
  bx lr
  

sub:
  ldr r4, addr_of_return2
  str lr , [r4]

  sub r3, r1, r2
  ldr r0, addr_of_message_sub
  bl printf  

  ldr lr, addr_of_return2
  ldr lr, [lr]
  
  bx lr

mul:
  ldr r4, addr_of_return2
  str lr , [r4]

  mul r3, r1, r2
  ldr r0, addr_of_message_mul
  bl printf  

  ldr lr, addr_of_return2
  ldr lr, [lr]
  
  bx lr


div:
  ldr r4, addr_of_return2
  str lr , [r4]

  sdiv r3, r1, r2
  ldr r0, addr_of_message_div
  bl printf  

  ldr lr, addr_of_return2
  ldr lr, [lr]
  
  bx lr

.global main
main:

  ldr r1, addr_of_return
  str lr, [r1]

  /* print first number */
  ldr r0, addr_of_message1
  bl printf

  /* scan first number */	
  ldr r0, addr_of_scan_pattern
  ldr r1, addr_of_number_read1			/* r1 <- second number */
  bl scanf

  /* abnormal input */ 
  cmp r0, #0
  beq end
			
  /* print second number */
  ldr r0, addr_of_message2
  bl printf

  /* scan second number */	
  ldr r0, addr_of_scan_pattern
  ldr r1, addr_of_number_read2			/* r2 <- second number */
  bl scanf
   
  /* abnormal input */ 
  cmp r0, #0
  beq end

  /* print all */
  ldr r2, addr_of_number_read2
  ldr r2, [r2]
  ldr r1, addr_of_number_read1
  ldr r1, [r1]
  ldr r0, addr_of_message3
  bl printf

  /* add() */
  ldr r1, addr_of_number_read1
  ldr r1, [r1]
  ldr r2, addr_of_number_read2
  ldr r2, [r2]
  bl add

  /* sub() */
  ldr r1, addr_of_number_read1
  ldr r1, [r1]
  ldr r2, addr_of_number_read2
  ldr r2, [r2]
  bl sub

  /* mul() */
  ldr r1, addr_of_number_read1
  ldr r1, [r1]
  ldr r2, addr_of_number_read2
  ldr r2, [r2]
  bl mul

  /* div() */
  ldr r1, addr_of_number_read1
  ldr r1, [r1]

  cmp r1, #0
  beq end

  ldr r2, addr_of_number_read2
  ldr r2, [r2]

  cmp r2, #0
  beq end

  bl div

  /* go to main  */
  ldr lr, addr_of_return
  ldr lr, [lr]
  bx lr


end:
  mvn r0, #-1
  add r0, r0, #1
  mov r1, r0
  ldr r0, addr_of_message_error
  bl printf

  ldr lr, addr_of_return
  ldr lr, [lr]
  bx lr


addr_of_message1 : .word message1
addr_of_message2 : .word message2
addr_of_message3 : .word message3
addr_of_message_add : .word message_add
addr_of_message_sub : .word message_sub
addr_of_message_mul : .word message_mul
addr_of_message_div : .word message_div
addr_of_message_error : .word message_error
addr_of_scan_pattern : .word scan_pattern
addr_of_number_read1 : .word number_read1
addr_of_number_read2 : .word number_read2
addr_of_return : .word return
addr_of_return2 :.word return2

.global printf
.global scanf
