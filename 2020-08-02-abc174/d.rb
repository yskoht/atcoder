n = gets.to_i
c = gets.chomp.split('')

w = 0
r = c.size-1

cnt = 0
while w < r
  if c[w] == 'W' && c[r] == 'R'
    cnt += 1
    w += 1
    r -= 1
  elsif c[w] != 'W'
    w += 1
  elsif c[r] != 'R'
    r -= 1
  end
end

puts cnt