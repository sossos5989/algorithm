let bool_array = Array.make 100000 false;;
let condition = ref false;;

let input = Scanf.scanf "%s" (fun x -> x)
let rec calc str =
  let digit = int_of_char str.[0] - int_of_char '0' in
  let len = String.length str in
  let answer = digit * len in
  (if bool_array.(answer) = true then condition := true
  else bool_array.(answer) <- true);

  if string_of_int answer = str then ()
  calc (string_of_int answer)

let _ =
  calc input;
  if !condition then Printf.printf "FA"
  else Printf.printf "NFA"
