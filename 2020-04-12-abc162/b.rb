n = gets.chomp.to_i

cnt = 0
1.upto(n) do |i|
 next if i % 3 == 0 || i % 5 == 0
 cnt += i
end

puts cnt
