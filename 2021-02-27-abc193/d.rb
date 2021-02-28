
def point(arr)
  res = 0
  1.upto(9) do |i|
    res += i * (10 ** arr.count(i))
  end
  res
end

k = gets.to_i
s = gets.chomp.split('')[0..-2].map(&:to_i)
t = gets.chomp.split('')[0..-2].map(&:to_i)

tmp = s + t

cards_sum = 0
cards = Array.new(10)
1.upto(9) do |i|
  cards[i] = k - tmp.count(i)
  cards_sum += cards[i]
end

ans = 0
1.upto(9) do |a|
  next if cards[a] <= 0
  ca = cards[a]
  cards[a] -= 1
  1.upto(9) do |b|
    next if cards[b] <= 0
    cb = cards[b]

    sp = point(s + [a])
    tp = point(t + [b])

    if sp > tp
      ans += (ca.to_f / cards_sum.to_f) * (cb.to_f / (cards_sum - 1).to_f)
    end
  end
  cards[a] += 1
end

puts ans
