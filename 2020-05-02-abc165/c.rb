$n, $m, $q = gets.chomp.split.map(&:to_i)

$t = []
$q.times do
  a, b, c, d = gets.chomp.split.map(&:to_i)
  a -= 1
  b -= 1
  $t.push [a, b, c, d]
end

$res = 0

def f(i, s)
  if s.size == $n
    r = 0
    $t.each do |a, b, c, d|
      r += d if s[b] - s[a] == c
    end
    $res = [$res, r].max
    return
  end

  i.upto($m) do |j|
    ss = s.clone
    ss.push j
    f(j, ss)
  end
end


f(1, [])

puts $res