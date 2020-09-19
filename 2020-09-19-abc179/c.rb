n = gets.to_i

cnt = 0
1.upto(n) do |i|
  k = n / i
  k -= 1 if n % i == 0
  cnt += k
end

puts cnt