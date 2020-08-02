k = gets.to_i

cnt = 1
a = 7
t = a % k
while t != 0
  a = t * 10 + 7
  cnt += 1
  break if cnt > 1000000
  t = a % k
end

puts t != 0 ? -1 : cnt
