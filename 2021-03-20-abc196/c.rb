x = gets.chomp

d = x.size
n = x.to_i

k = d / 2

t = [0]
15.times do |i|
  t.push 9 * (10 ** i)
end

res = 0
0.upto(k-1) do |i|
  res += t[i]
end

fr = k - 1 >= 0 ? 10 ** (k - 1) : 1
to = (10 ** k) - 1

fr.upto(to) do |i|
  tmp = (i.to_s * 2).to_i
  if tmp <= n
    res += 1
  else
    break
  end
end

puts res
