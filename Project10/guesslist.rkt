(#%require (lib "27.ss" "srfi"))
(random-source-randomize! default-random-source)
(define print_list
  (lambda (L)
    ...))

(define players '())

;Helper function to print the name
(define congratulate
  (lambda (name)
    (display (string-append "Good game, " name "!"))
    (newline)
  ))

;Primary mechanics
(define (get_guess target guesses)
    (display "Enter guess: " )
    (let ((guess (read)))
      (cond
        ((= guess target)
         (begin
           (display (string-append "Correct! You made " (number->string guesses) " guesses..."))
           (newline)
           (display "Please enter your name: ")
           (let ((name (read)))
             (begin 
               (congratulate (symbol->string name))
               (list (list name guesses))))))
        ((< guess target)
         (display "Higher...")
         (get_guess target (+ guesses 1)))
        ((> guess target)
         (display "Lower...")
         (get_guess target (+ guesses 1))))))


(define (play_guess target init)
  (display "Guess a number from 1 to 10")
  (newline)
  (get_guess target init))

(define (show-scores sl)
  (if (null? sl)
      (values)
      (begin
        (display "---------------")
        (newline)
        (display (string-append (symbol->string (caar sl)) " " (number->string (cadr (car sl)))))
        (newline)
        (show-scores (cdr sl)))))

; Generate random number and play the game
(define (play players)
    (begin
      (display "Enter 'q' to quit or any other key to continue: ")
      (let ((answer (read)))
        (if (string=? "q" (symbol->string answer))
            (show-scores players)
            (play (append players (play_guess (+ (random-integer 9) 1) 1)))))))


(play players)
