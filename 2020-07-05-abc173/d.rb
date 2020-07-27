n = gets.to_i
a = gets.chomp.split.map(&:to_i).sort.reverse

ans = a[0]
a = a[1..-1]

if n != 2
  i = 0
  cnt = 0
  loop {
    ans += a[i]
    cnt += 1
    break if cnt >= a.size - 1
    ans += a[i]
    cnt += 1
    break if cnt >= a.size - 1
    i += 1
  }
end

puts ans