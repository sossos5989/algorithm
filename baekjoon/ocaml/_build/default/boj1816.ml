let rec solve n =
  match n with
  | 0 -> ()
  | t -> 
      let input = Scanf.scanf "%s" (fun x -> x) in
      let s = input in
      let len = String.length s in
      if len < 8 then
        Printf.printf "문자열 길이가 충분하지 않습니다: %s\n" s
      else
        let sub = String.sub s (len - 8) 7 in
        let k = int_of_string sub in
        Printf.printf "추출한 정수: %d\n" k;
      solve (t - 1)
      
in solve (Scanf.scanf "%d" (fun x -> x))